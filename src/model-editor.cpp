#include <iostream>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Usage: model-editor --model FILE --target JSON_FILE" << std::endl;
        std::cout << "  --model FILE    Model file name" << std::endl;
    }


    return 0;
}