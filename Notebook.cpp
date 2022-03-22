#include "Direction.hpp"
#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>
#include "Notebook.hpp"

using ariel::Direction;
using namespace std;

namespace ariel{
    
    void Notebook::write(unsigned int page, unsigned int row, unsigned int col, Direction direction, const string & data){
        unsigned int data_len = data.length();
        if(col > 100 || (direction == Direction::Horizontal && col + data_len > 100)){throw runtime_error("Writing in illegal columns!");}
        for (size_t i = 0; i < data_len -1; i++){
            if (data[i] < 32 || data[i] > 126){
                throw runtime_error("The char u picked is not printable!");}
            }
            
        }
    string Notebook::read(unsigned int page, unsigned int row, unsigned int col, Direction direction, unsigned int readLength){
        if(col > 100 || (direction == Direction::Horizontal && col + readLength > 100)){throw runtime_error("Some of the lines you want to read do not exist!");}
        return "";
    }
    void Notebook::erase(unsigned int page, unsigned int row, unsigned int col, Direction direction, unsigned int eraselength){
        if(col > 100 || (direction == Direction::Horizontal && col + eraselength > 100)){throw runtime_error("Some of the lines you want to erase do not exist!");}
    }
    void Notebook::show(unsigned int page){
        
    }
}