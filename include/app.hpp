#ifndef APP_H_
#define APP_H_

#include "engine_device.hpp"
#include "lve_pipeline.hpp"
#include "lve_window.hpp"

namespace lve {

class App {

public:
  static constexpr int HEIGHT = 600;
  static constexpr int WIDTH = 800;
  void run();

private:
  LveWindow lveWin{WIDTH, HEIGHT, "Geng"};
  EngineDevice lveDevice{lveWin};
  LvePipeline lvePipeline{
      lveDevice, "/home/scott/Exploits/GForm/shaders/vertex_shader.vert.spv",
      "/home/scott/Exploits/GForm/shaders/frag_shader.frag.spv",
      LvePipeline::defaultPipelineConfigInfo(WIDTH, HEIGHT)};
};

} // namespace lve

#endif // APP_H_
