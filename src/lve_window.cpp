#include "../include/lve_window.hpp"
#include <GLFW/glfw3.h>
#include <exception>
#include <stdexcept>

namespace lve {

LveWindow::LveWindow(int w, int h, std::string wName)
    : width(w), height(h), windowName(wName) {
  initWindow();
}

LveWindow::~LveWindow() {
  glfwDestroyWindow(win);
  glfwTerminate();
}

void LveWindow::initWindow() {
  glfwInit();
  glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
  glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

  win = glfwCreateWindow(width, height, windowName.c_str(), nullptr, nullptr);
}

void LveWindow::createWindowSurface(VkInstance instance,
                                    VkSurfaceKHR *surface) {
  if (glfwCreateWindowSurface(instance, win, nullptr, surface) != VK_SUCCESS) {
    throw std::runtime_error("Failed to create window surface!");
  }
}

} // namespace lve
