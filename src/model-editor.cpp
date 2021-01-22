#include <memory>
#include <iostream>

//#include "model.h"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Usage: model-editor --model FILE --target JSON_FILE" << std::endl;
        std::cout << "  --model FILE    Model file name" << std::endl;
    }
    // std::unique_ptr<onnx::ModelProto> model_proto;
    // model_proto.reset(new onnx::ModelProto());


    return 0;
}