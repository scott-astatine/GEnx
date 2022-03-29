#include "../include/app.hpp"

namespace lve {
void App::run() {
  while (!lveWin.shouldClose()) {
    glfwPollEvents();
  }
}
} // namespace lve
