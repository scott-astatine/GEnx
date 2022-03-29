#ifndef LVE_WINDOW_H_
#define LVE_WINDOW_H_

#include <string>
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

namespace lve {

class LveWindow {
public:
  LveWindow(int w, int h, std::string wName);
  ~LveWindow();

  LveWindow(const LveWindow &) = delete;
  LveWindow &operator=(const LveWindow &) = delete;

  bool shouldClose() { return glfwWindowShouldClose(win); }
  void createWindowSurface(VkInstance instance, VkSurfaceKHR *surface);

private:
  void initWindow();
  const int width;
  const int height;
  std::string windowName;
  GLFWwindow *win;
};

} // namespace lve

#endif // LVE_WINDOW_H_
