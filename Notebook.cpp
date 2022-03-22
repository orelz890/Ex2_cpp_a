#include "Direction.hpp"
#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>
#include "Notebook.hpp"

using ariel::Direction;
using namespace std;

namespace ariel{
    
    void Notebook::write(unsigned int page, unsigned int row, unsigned int col, Direction direction, string data){
        return;
    }
    string Notebook::read(unsigned int page, unsigned int row, unsigned int col, Direction direction, unsigned int readLength){
        return "";
    }
    void Notebook::erase(unsigned int page, unsigned int row, unsigned int col, Direction direction, unsigned int eraselength){
        return;
    }
    void Notebook::show(unsigned int page){
        return;
    }
}