#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include "Direction.hpp"

using namespace std;
using namespace ariel;

#define MIN_CHAR 32
#define MAX_CHAR 126
#define LINE_LEN 100
#define MIN_POSITION 0

namespace ariel{
    class Notebook
    {
    private:
        int lineSize = 100;
        vector<vector<char>> notebook;
    public:
        void write(int page, int row, int col, Direction direction, const string & data);
        string read(int page, int row, int col, Direction direction, int readLength);
        void erase(int page, int row, int col, Direction direction, int eraselength);
        void show(int page);
        int get_line_size(){
             return lineSize;
        }
        void open_new_notebook(){
            notebook.clear();
        }
    };
};