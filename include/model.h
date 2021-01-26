#ifndef MODEL_EDITOR_MODEL_H_
#define MODEL_EDITOR_MODEL_H_

#include <memory>
#include <string>
#include <vector>

#include "types.h"
#include "onnx-ml.pb.h"

namespace model_editor {

class Graph {
public:
    Graph();

//private:
    // std::vector<std::unique_ptr<Node>> nodes_;
    // std::vector<std::unique_ptr<Tensor>> tensors_;
};

class Model {
public:
    Model(std::string file_name);

    //std::vector<std::unique_ptr<Graph>> subgraphs();

    const std::string& producer_name();

    std::string description();

    int set_producer_name(std::string& new_name);

    int save(std::string new_file_name="");

private:
    std::string file_name_;
    std::unique_ptr<onnx::ModelProto> model_;
    //std::vector<std::unique_ptr<SubGraph>> subgraph_;
    //int64 version_;
    std::string proceducer_name_;
    std::string proceducer_version_;
    std::string description_;

};

} // namespace model_editor

#endif  // __MODEL_EDITOR_MODEL_H_