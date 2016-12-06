#include <windows.h>
#include <string>
#include <iostream>

#include <destructor.h>
#include <LsWin32MainWindow.h>
#include <LsRenderer.h>
#include <LsVulkanLoader.h>
#include <LsWintabLoader.h>
#include <LsBrushRig.h>
#include <LsPointGrid.h>
#include <LsUselessBox.h>
#include <LsConsole.h>
#include <LsError.h>
#include <Test.h>

using namespace lslib;

class Application {
  LsWin32MainWindow* window;
  LsBrushRig brushRig;
  LsPointGrid pointGrid;
  LsUselessBox uselessBox;
  LsRenderer* renderer;
public:
  Application() {
    LsCloseConsole();
    LsUnloadWintabLibrary();
  }

  ~Application() {}

  void Initialize(HINSTANCE hInstance) {
    // Attach console
    LsOpenConsole();

    // Get a pointer to main window singleton
    window = LsWin32MainWindow::Get();

    // Load Wintab
    LsLoadWintabLibrary();
    LsLoadWintabEntryPoints();
   
    window->Create(hInstance, "Lustrious Paint", 100, 100, 1024, 640);
    LsSetDialogParentWindow(window->GetWindowHandle());

    window->HideMouse();

    // Initialize the rendering system
    LsRenderer::Initialize(hInstance, window->GetWindowHandle());

    renderer = LsRenderer::Get();

    pointGrid.SetBackgroundColor(0.1f, 0.0f, 0.1f);
  }

  void Run() {
    window->Show();
    while( window->ProcessNextMessage() ){
      window->WaitForMessages();
      renderer->BeginFrame();
      pointGrid.Render();
      brushRig.Render();
      uselessBox.Render();
      renderer->EndFrame();
    };
  }
};

int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
  try {
    Application application;
    application.Initialize(hInstance); test();
    application.Run();
  }
  catch (std::string m) {
    LsErrorMessage(m, "Error");
  }
}