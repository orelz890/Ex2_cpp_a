#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include "Direction.hpp"

using namespace std;
using namespace ariel;
namespace ariel{
    class Notebook
    {
    private:
        int lineSize = 100;
        vector<vector<char>> notebook;
    public:
        void write(unsigned int page, unsigned int row, unsigned int col, Direction direction, string data);
        string read(unsigned int page, unsigned int row, unsigned int col, Direction direction, unsigned int readLength);
        void erase(unsigned int page, unsigned int row, unsigned int col, Direction direction, unsigned int eraselength);
        void show(unsigned int page);
        int get_line_size(){
             return lineSize;
        }
        void open_new_notebook(){
            notebook.clear();
        }
    };
};