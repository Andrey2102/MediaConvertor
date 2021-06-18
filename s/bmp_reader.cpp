#include <iostream>
#include <string.h>
#include <fstream>
#include <vector>
#include "bmp_reader.h"
#include "convertor.h"


void save(std::string path_to_file)
{
    
}

const void BMP::print()
{
    std::cout << "type:               " << type[0] << type[1] << std::endl;
    std::cout << "file_size:          " << file_size << std::endl;
    std::cout << "reserved1:          " << reserved1 << std::endl;
    std::cout << "reserved2:          " << reserved2 << std::endl;
    std::cout << "offset_bits:        " << offset_bits << std::endl;
    
    //BitMap Info Header
    std::cout << "header_size:        " << header_size << std::endl;
    std::cout << "img_width:          " << img_width << std::endl;
    std::cout << "img_hight:          " << img_hight << std::endl;

    std::cout << "planes:             " << planes << std::endl;
    std::cout << "bit_cnt:            " << bit_cnt << std::endl;

    std::cout << "compression:        " << compression << std::endl;
    std::cout << "size_img:           " << size_img << std::endl;
    std::cout << "x_pels_per_meter:   " << x_pels_per_meter << std::endl;
    std::cout << "y_pels_per_meter:   " << y_pels_per_meter << std::endl;
    std::cout << "colors_used:        " << colors_used << std::endl;
    std::cout << "main_colors_cnt:    " << main_colors_cnt << std::endl;
}

void BMP::copy(const BMP &other)
{
    this->type[0] = other.type[0];
    this->type[1] = other.type[1];

    this->file_size = other.file_size;
    this->reserved1 = other.reserved1;
    this->reserved2 = other.reserved2;
    this->offset_bits = other.offset_bits;
    
    //BitMap Info Header
    this->header_size = other.header_size;
    this->img_width = other.img_width;
    this->img_hight = other.img_hight;

    this->planes = other.planes;
    this->bit_cnt = other.bit_cnt;

    this->compression = other.compression;
    this->size_img = other.size_img;
    this->x_pels_per_meter = other.x_pels_per_meter;
    this->y_pels_per_meter = other.y_pels_per_meter;
    this->colors_used = other.colors_used;
    this->main_colors_cnt = other.main_colors_cnt;
}

BMP::BMP(std::string path_to_image)
{
    
    //read_img_to_buf(path_to_image, img_byte_buff);
    const char * path = "C:\\Users\\adm\\univer\\cg\\MediaConvertor\\bmp\\grad.bmp";
    FILE* file = fopen(path, "rb");
    char *tmp = new char[sizeof(BMP)];
    fread(tmp, sizeof(BMP), 1, file);
    if( img_byte_buff == nullptr)
    {
        this->~BMP();
    }

    //offset +0
    type[0] = 'B';
    type[1] = 'M';
    //offset +2
    file_size = (unsigned int)*(tmp + 2);
    
    //offset +6
    reserved1 = (unsigned short)*(tmp + 6);
    
    //offset +8
    reserved2 = (unsigned short)*(tmp + 8);
    
    //offset +10
    offset_bits = (unsigned int)*(tmp + 10);
    
    //BitMap Info Header
    //offset +14
    header_size = (unsigned int)*(tmp + 14);
    //offset +18
    img_width = (unsigned int)*(tmp + 18);
    //offset +22
    img_hight = (unsigned int)*(tmp + 22);
    //offset +26
    planes = (unsigned short)*(tmp + 26);
    //offset +28
    bit_cnt = (unsigned short)*(tmp + 28);
    //offset +30
    compression = (unsigned int)*(tmp + 30);
    //offset +34
    size_img = (unsigned int)*(tmp + 34);
    //offset +38
    x_pels_per_meter = (unsigned int)*(tmp + 38);
    //offset +42
    y_pels_per_meter = (unsigned int)*(tmp + 42);
    //offset +46
    colors_used = (unsigned int)*(tmp + 46);
    //offset +50
    main_colors_cnt = (unsigned int)*(tmp + 50);
    print();
//offset +56

    //Color Table
    int color_table [256];
}

BMP::~BMP()
{
    delete[] img_byte_buff;
}


void BMP::init_fields()
{
    std::cout << "Size: " << file_size << std::endl;

}