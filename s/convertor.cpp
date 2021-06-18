#include <fstream>
#include <string>
#include <iostream>
#include "convertor.h"

void read_img_to_buf(std::string INPUT_FILENAME, char *&IMG_BUFF)
{
    std::ifstream is (INPUT_FILENAME, std::ifstream::binary);
    if (!is) {
        IMG_BUFF = nullptr;
    }
    else{
        // get length of file:
        is.seekg (0, is.end);
        int length = is.tellg();
        is.seekg (0, is.beg);

        // allocate memory:
        IMG_BUFF = new char [length];

        // read data as a block:
        is.read (IMG_BUFF,length);
    }
    is.close();

}