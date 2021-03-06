#include <windows.h>
#include <iostream>
#include <glm/glm.hpp>
#include <LsRenderer.h>
#include <LsUselessBox.h>
#include <LsWin32MainWindow.h>

LsUselessBox::LsUselessBox(std::shared_ptr<LsRenderer> renderer) :renderer(renderer) {}

LsUselessBox::~LsUselessBox() {

}

void LsUselessBox::Render() {
  renderer->SetColor(1.0f, 1.0f, 1.0f);
  renderer->SetLineWidth(1.0f);
  renderer->DrawLine(x, y, x + width, y);
  renderer->DrawLine(x, y, x, y + height);
  renderer->DrawLine(x, y + width, x + width, y + height);
  renderer->DrawLine(x + width, y, x + width, y + height);
}

bool LsUselessBox::HitTest(POINT point) {
  return point.x >= x && point.x <= (x + width) && point.y >= y && point.y <= (y + height);
}

void LsUselessBox::OnWin32Message(UINT uMsg, WPARAM wParam, LPARAM lParam) {
  POINT cursor;
  switch (uMsg) {
    case WM_MOUSELEAVE:
    dragging = false;
    break;
    case WM_MOUSEMOVE:
    
    if (painting)
    {
      cursor = LsWin32MainWindow::Get()->GetMousePosition();
      renderer->CanvasStroke(cursor.x, cursor.y, 2.0f);
    }
    if ( dragging ) {
      cursor = LsWin32MainWindow::Get()->GetMousePosition();
      x = (float)(cursor.x - grabOffset.x);
      y = (float)(cursor.y - grabOffset.y);
    }
    break;
    case WM_LBUTTONDOWN:
    cursor = LsWin32MainWindow::Get()->GetMousePosition();
    painting = true;
    if ( HitTest(cursor) ) {
      dragging = true;
      grabOffset.x = cursor.x - x;
      grabOffset.y = cursor.y - y;
    }
    break;
    case WM_LBUTTONUP:
    dragging = false;
    painting = false;
    break;
  }
}