// WidgetFrameworkCreator.cpp
#include "WidgetFrameworkCreator.h"
#include "Blueprint/WidgetTree.h"
#include "Kismet2/BlueprintEditorUtils.h"
#include "WidgetBlueprint.h"
#include "WidgetBlueprintFactory.h"
#include "AssetToolsModule.h"
#include "EditorAssetLibrary.h"
#include "Misc/MessageDialog.h"
#include "Engine/Font.h"

void UWidgetFrameworkCreator::CreateRootWidgetBP(const FString& PackagePath, UFont* Font, const FString& AssetName)
{
    // Lambda function to convert an absolute file system path into a valid Unreal package path (e.g., "/Game/...")
    auto ConvertAbsoluteToPackagePath = [](const FString& AbsolutePath) -> FString
        {
            FString ContentDir = FPaths::ConvertRelativePathToFull(FPaths::ProjectContentDir());
            FString FullPath = FPaths::ConvertRelativePathToFull(AbsolutePath);

            if (FullPath.StartsWith(ContentDir))
            {
                FString RelativePath = FullPath.RightChop(ContentDir.Len());
                RelativePath = RelativePath.Replace(TEXT("\\"), TEXT("/"));
                return FString::Printf(TEXT("/Game/%s"), *RelativePath);
            }
            return FString();
        };

    // Convert the given path to a valid UE asset path
    FString PackagePathUE = ConvertAbsoluteToPackagePath(PackagePath);
    if (PackagePathUE.IsEmpty())
    {
        UE_LOG(LogTemp, Error, TEXT("Failed to convert package path."));
        return;
    }

    // Combine the path and asset name into a full asset reference
    const FString FullPackageName = PackagePathUE / AssetName;

    // Check if the asset already exists to avoid duplication
    if (UEditorAssetLibrary::DoesAssetExist(FullPackageName))
    {
        UE_LOG(LogTemp, Warning, TEXT("Asset %s already exists!"), *FullPackageName);
        return;
    }

    // Create a new Widget Blueprint asset
    UWidgetBlueprintFactory* Factory = NewObject<UWidgetBlueprintFactory>();
    Factory->ParentClass = UUserWidget::StaticClass();

    FAssetToolsModule& AssetToolsModule = FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools");
    UObject* NewBPObj = AssetToolsModule.Get().CreateAsset(AssetName, PackagePathUE, UWidgetBlueprint::StaticClass(), Factory);
    UWidgetBlueprint* WidgetBP = Cast<UWidgetBlueprint>(NewBPObj);

    if (!WidgetBP)
    {
        UE_LOG(LogTemp, Error, TEXT("Failed to create Widget Blueprint!"));
        return;
    }

    // Get the WidgetTree from the newly created Blueprint
    UWidgetTree* Tree = WidgetBP->WidgetTree;
    Tree->Modify(); // Allow undo/redo tracking in editor

    // Use the given font, or fallback to engine's default medium font if null
    Font = Font ? Font : GEngine->GetMediumFont();

    /*================================= Start ===================================*/

    // Place full widget construction logic here
    // (e.g., Create Canvas Panel, Buttons, Layout, etc.)

    /*================================== End ====================================*/

    // Mark the Blueprint as structurally modified so the editor saves and compiles it properly
    FBlueprintEditorUtils::MarkBlueprintAsStructurallyModified(WidgetBP);

    UE_LOG(LogTemp, Log, TEXT("UMG widget hierarchy successfully generated!"));
}
