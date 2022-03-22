#include "doctest.h"
#include "Notebook.hpp"
#include <string>
#include <algorithm>

using namespace ariel;
using ariel::Direction;
using ariel::Notebook;
using namespace std;

// In all Notebook functons(except show) that we will test, the first 4 input values are: 
// (page: int, row: int, col: int, direction: Direction).

Notebook n;
int page0 = 0;

TEST_CASE("Good writing/reading/erasing"){
    n.write(page0,0,0,Direction::Horizontal,"Hey");
    CHECK (n.read(page0, 0, 0, Direction::Horizontal, 3) == "Hey");
    n.write(page0,14,0,Direction::Horizontal,"second test");
    CHECK (n.read(page0, 14, 0, Direction::Horizontal, 11) == "second test");
    for (size_t row = 0; row < 13; row++){
        for (size_t col = 0; col < 100; col++){
            if (row == 0 && col > 3){
                CHECK(n.read(page0,row,col,Direction::Horizontal ,1) == "_");
            }else if(row != 0){
                CHECK(n.read(page0,row,col,Direction::Horizontal ,1) == "_");
            }
        }
    }
    n.write(page0,0,10,Direction::Vertical,"vertical test");
    CHECK (n.read(page0, 0, 10, Direction::Vertical, 13) == "vertical test");

    // Checking that the notebook was filled by under score (_) in the empty cels created between the writed data
    CHECK(n.read(page0,0,4,Direction::Horizontal ,5) == "_____");
    for (size_t row = 0; row < 13; row++){
        for (size_t col = 0; col < 100; col++){
            if (row != 0 && col == 0){
                CHECK(n.read(page0,row,0,Direction::Horizontal ,9) == "_________");
                col += 10;
            }else if (row < 12){
                CHECK(n.read(page0,row,col,Direction::Horizontal ,1) == "_");
            }        
        }
    }
    // Checking erase horizontal & vertical
    n.erase(0,0,0,Direction::Horizontal,3);
    CHECK (n.read(0, 0, 0, Direction::Horizontal, 3) == "~~~");
    n.erase(0,0,10,Direction::Vertical, 13);
    CHECK (n.read(0,0,10,Direction::Vertical,13) == "~~~~~~~~~~~~~");
}


Notebook n2;

TEST_CASE("Bad input") {
    n2.write(0,0,1,Direction::Vertical,"OrelZamler");
    n2.erase(0,0,5,Direction::Horizontal,6);
    for (size_t i = 0; i < 255; i++){
        char c = i;
        string s = "" + c;

        // Char is printable. Check writing overiding:
        if (i >= 32 && i <= 126){
            string over_riding_one_char = s;
            string over_riding_the_entire_word = "Word";
            string over_riding_and_more = "Word" + c;
            string over_riding_erased_data = "Zamler";
            string over_riding_erased_data_and_more = "OrelZ";
            string over_riding_erased_and_written_data = "OrelZamler";

            CHECK_THROWS(n2.write(0,0,1,Direction::Horizontal,over_riding_one_char));
            CHECK_THROWS(n2.write(0,0,1,Direction::Horizontal,over_riding_the_entire_word));
            CHECK_THROWS(n2.write(0,0,0,Direction::Vertical,over_riding_and_more));
            CHECK_THROWS(n2.write(0,0,5,Direction::Vertical,over_riding_erased_data));
            CHECK_THROWS(n2.write(0,0,5,Direction::Vertical,over_riding_erased_data_and_more));
            CHECK_THROWS(n2.write(0,0,0,Direction::Vertical,over_riding_erased_and_written_data));
        }
        // Char is not printabe throw exception!
        else{
            CHECK_THROWS(n2.write(0, i%10, i%100, Direction::Horizontal, s));
            CHECK_THROWS(n2.write(0, i%10, i%100, Direction::Horizontal, "legal string" + s));
        }
    } 
    CHECK_THROWS ();
}
