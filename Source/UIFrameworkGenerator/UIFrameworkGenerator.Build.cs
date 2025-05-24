using UnrealBuildTool;

public class UIFrameworkGenerator : ModuleRules
{
    public UIFrameworkGenerator(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[]
        {
            "Core",
            "CoreUObject",
            "Engine",
            "UMG"
        });

        PrivateDependencyModuleNames.AddRange(new string[]
        {
            "Slate",
            "SlateCore",
            "UMG",
            "AssetTools",
            "EditorScriptingUtilities",
            "Blutility"
        });

        if (Target.bBuildEditor)
        {
            PrivateDependencyModuleNames.AddRange(new string[]
            {
                "UnrealEd",
                "UMGEditor"
            });

            PrivateIncludePathModuleNames.AddRange(new string[]
            {
                "AssetTools",
                "EditorScriptingUtilities",
                "Blutility"
            });
        }
    }
}
