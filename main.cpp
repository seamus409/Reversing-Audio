//
//  main.cpp
//  Conditional Audio Manipulator
//
//  Created by Account1 on 14/01/2022.
//  Copyright © 2022 SeamusHeath. All rights reserved.
//


#include <iostream>
#include <fstream>
#include <cmath>
#include <math.h>
#include <ctime>
#include <string>

#define PI 3.14159265

int main() {
    
    FILE * pFile;
    
    char input[]="/Users/russian/Desktop/example.wav";

    std::ifstream infile (input,std::ifstream::binary);
    std::ifstream infile2 (input,std::ifstream::binary);

    //get size of file
    infile.seekg (0,infile.end);
    long size = infile.tellg();
    infile.seekg(0);
    std::cout<<size;
    //allogate memory for file content
    char* buffer = new char[size];
    char* bfpt= new char[size];

    //read content of infile
    infile.read(buffer,size);
    infile2.read(bfpt,size);
    int file_header_length=40000;//temp
    int file_end_length=20000;
    int sample_chunks_number=5;
    
    /*3.3s3 Altering audio file code*/
    int max=round((size-file_end_length));
    for (int x=file_header_length; x<max-5;x++){
        for (int scn=0;scn<sample_chunks_number+1;scn++){
            buffer[x+scn]= bfpt[size-file_end_length-(x+scn)+1];
        }
    }

    //time
    time_t now = time(0);
    // convert time to string form
    char* dt = ctime(&now);
    std::string ofile ("/Users/russian/Desktop/DIY Samples/RESULTS/SH_TEST_SPEECH_");
    ofile += dt;
    ofile += ".wav";
    std::cout<<ofile;
    //char output[]="/Users/russian/Desktop/DIY Samples/RESULTS/.wav";
    std::ofstream outfile (ofile, std::ofstream::binary);
    
    //write to outfile
    outfile.write(buffer,size);
    delete[] buffer;
    delete[] bfpt;
    outfile.close();
    infile.close();
    infile2.close();
    return 0;
}
