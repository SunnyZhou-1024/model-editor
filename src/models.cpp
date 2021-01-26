#include <fcntl.h>
#include <sys/stat.h>
#include <string>
#include <utility>


#include "model.h"
#include "utils.h"

namespace model_editor {

Model::Model(std::string model_name): file_name_(model_name) {
    int fd = open(model_name.c_str(), O_RDWR);
    onnx::ModelProto* model = new onnx::ModelProto();
    model->ParseFromFileDescriptor(fd);
    model_.reset(model);
    close(fd);
}

std::string Model::description() {

}

int Model::set_producer_name(std::string& new_name) {
    model_.get()->set_producer_name(new_name);
    return 0;
}



int Model::save(std::string new_file_name) {
    struct stat buf;
    int status = stat(file_name_.c_str(), &buf);

    int fd = -1;
    if (new_file_name == "") 
        fd = open(file_name_.c_str(), O_RDWR);
    else
        fd = creat(new_file_name.c_str(), buf.st_mode);


    model_.get()->SerializeToFileDescriptor(fd);
    close(fd);

    return 0;
}
//std::string Model::subgraphs() {}

const std::string& Model::producer_name() {
    return model_.get()->producer_name();
}
}



