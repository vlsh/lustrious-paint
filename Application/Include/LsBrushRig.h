#pragma once

#include <memory>
#include <windows.h>
#include <LsFWin32MessageHandler.h>
#include <LsMath.h>
#include <LsRenderer.h>

class LsBrushRig: public LsFWin32MessageHandler
{
  std::shared_ptr<LsRenderer> renderer;
  struct {
    float position[2];
    float orientation[2] = { kPI, kPI/2.0f };
    float pressure;
  } penStatus;
 
public:
  LsBrushRig(std::shared_ptr<LsRenderer> renderer);
  ~LsBrushRig();
  void OnWin32Message(UINT uMsg, WPARAM wParam, LPARAM lParam) override;
  void Render();
};
