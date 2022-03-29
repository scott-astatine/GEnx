#ifndef LVE_PIPELINE_H_
#define LVE_PIPELINE_H_

#include <cstdint>
#include <string>
#include <vector>

#include "engine_device.hpp"

namespace lve {

struct PipelineConfigInfo {
  VkPipelineViewportStateCreateInfo viewportInfo;
  VkPipelineInputAssemblyStateCreateInfo inputAssemblyInfo;
  VkPipelineRasterizationStateCreateInfo rasterizationInfo;
  VkPipelineMultisampleStateCreateInfo multisampleInfo;
  VkPipelineColorBlendAttachmentState colorBlendAttachment;
  VkPipelineColorBlendStateCreateInfo colorBlendInfo;
  VkPipelineDepthStencilStateCreateInfo depthStencilInfo;
  std::vector<VkDynamicState> dynamicStateEnables;
  VkPipelineDynamicStateCreateInfo dynamicStateInfo;
  VkPipelineLayout pipelineLayout = nullptr;
  VkRenderPass renderPass = nullptr;
  uint32_t subpass = 0;
};

class LvePipeline {

public:
  LvePipeline(EngineDevice &device, const std::string &vertFilePath,
              const std::string &fragFilePath,
              const PipelineConfigInfo configInfo);
  ~LvePipeline(){};
  LvePipeline(const LvePipeline &) = delete;
  void operator=(const LvePipeline &) = delete;

  static PipelineConfigInfo defaultPipelineConfigInfo(uint32_t width,
                                                      uint32_t height);

private:
  static std::vector<char> readFile(const std::string &filepath);

  void createGraphicsPipeline(const std::string &vertFilePath,
                              const std::string &fragFilePath,
                              const PipelineConfigInfo configInfo);
  void createShaderModule(const std::vector<char> &code,
                          VkShaderModule *shaderModule);

  EngineDevice &lveDevice;
  VkPipeline graphicsPipeline;
  VkShaderModule vertShaderModule;
  VkShaderModule fragShaderModule;
};

} // namespace lve

#endif // LVE_PIPELINE_H_
