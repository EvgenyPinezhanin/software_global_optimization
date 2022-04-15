#include "MainForm.h"
#include <Windows.h>
#pragma comment (lib, "Advapi32.lib")
#pragma comment (lib, "user32.lib")

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void main(cli::array<String^>^ args) {
    DPI_AWARENESS_CONTEXT value = DPI_AWARENESS_CONTEXT_SYSTEM_AWARE;
    SetProcessDpiAwarenessContext(value);

    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    softwareGlobalOptimization::MainForm form;
    Application::Run(% form);
}