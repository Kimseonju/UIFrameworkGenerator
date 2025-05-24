# UIFrameworkGenerator

**Unreal Engine plugin to automatically generate structured UMG widget hierarchies.**  
This tool is designed for UI developers and technical artists who want to automate repetitive layout work using programmatic definitions.

---

## ✨ Features

- 🧱 Automatically creates UMG widget hierarchies via C++
- 🎯 Canvas Panel–based layout with dynamic widget generation

---

## 📂 Example Output
```
CanvasPanel (Root) 
├── TextBlock ("Select Skill")
├── Button
│ └── Border
│ └── Border
│ └── HorizontalBox
```
## 🧠 How to Use

This plugin uses **ChatGPT or Claude** (AI) to generate Unreal C++ widget creation code and builds the actual UMG Blueprint inside the Unreal Editor.

---

### 1️⃣ Prompt ChatGPT or Claude (AI)

1. 🧾 **Provide your current file**:  
   Copy and paste your existing `WidgetFrameworkCreator.cpp` source file (or just the `CreateRootWidgetBP()` function).

2. 🖼️ **Include your design image**:  
   Add a screenshot, mockup, or layout sketch (e.g., Figma export) as visual reference.

3. 💬 **Prompt the AI with instructions**:

---

### 2️⃣ Paste Code into Plugin Source File

Paste the result into:
- Replace or modify the `CreateRootWidgetBP()` function.
- Be sure your function is properly defined and compiled.

---

### 3️⃣ Run the Plugin in Unreal Editor

1. Launch Unreal Editor
2. Enable `UIFrameworkGenerator` from **Plugins > Editor** section
3. Run the plugin via **Editor Utility Widget**
4. The widget will be generated and saved to: /Game


## ✅ Summary

| Step | Description |
|------|-------------|
| 1️⃣  | Prompt ChatGPT/Claude with widget structure |
| 2️⃣  | AI -  Design Image Input And Paste code into `WidgetFrameworkCreator.cpp` |
| 3️⃣  | Run the plugin to generate the Blueprint widget |

---

## 💡 Tips

- Use UTF-8 encoding when editing `.cpp` files

## Where Code?

    /*================================= Start ===================================*/

    // Place full widget construction logic here
    // (e.g., Create Canvas Panel, Buttons, Layout, etc.)

    /*================================== End ====================================*/
