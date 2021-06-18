#ifndef BMP_READER_H
#define BMP_READER_H

#include <iostream>
#include <string.h>

class BMP{

    //BitMap File Header
    unsigned char type[2];
    unsigned int file_size;
    unsigned short reserved1;
    unsigned short reserved2;
    unsigned int offset_bits;
    
    //BitMap Info Header
    unsigned int header_size;
    unsigned int img_width;
    unsigned int img_hight;

    unsigned short planes;
    unsigned short bit_cnt;

    unsigned int compression;
    unsigned int size_img;
    unsigned int x_pels_per_meter;
    unsigned int y_pels_per_meter;
    unsigned int colors_used;
    unsigned int main_colors_cnt;

    //Color Table
    int color_table [256];

    //BitMap Array
    char *img_byte_buff;

    void init_fields();

public:

    const void print();
    void save(std::string path_to_file);
    void copy(const BMP &other);
    BMP(){}
    BMP(std::string path_to_file);
    ~BMP();


};

#endif