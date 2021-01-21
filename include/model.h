#ifndef __MODEL_EDITOR_MODELS
#define __MODEL_EDITOR_MODELS

#include <memory>
#include <string>
#include <vector>

#include "types.h"

namespace model_editor {

class Graph {
public:
    Graph();

private:
    std::vector<std::unique_ptr<Node>> nodes_;
    std::vector<std::unique_ptr<Tensor>> tensors_;
    std::
}

class Model {
public:
    Model(std::string file_name);

    std::vector<std::unique_ptr<Graph>> subgraphs();

private:
    std::string file_name_;
    std::vector<std::unique_ptr<SubGraph>> subgraph_;
    int64 version_;
    std::string proceducer_name_;
    std::string proceducer_version_;
    std::string description_;

}
}

#endif  // __MODEL_EDITOR_MODELS