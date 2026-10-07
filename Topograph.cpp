#include "Picture.h"
#include "Topograph.h"
#include <iostream>
#include <fstream>
using namespace std;



    ///**************Part 1********************************
    ///Constructor.  Open a ArcGIS ASCII Grid file
    ///read the header to assign height and width
    ///resize v and read elevation data
    Topograph(string fileName) {


    }

    int getHeight() const {
        return height;
    }
    int getWidth() const {
        return width;
    }

    ///find min and max elevation values
    ///call mapRange to convert each elevation to grayscale
    ///set each Picture coordinate at (x,y) to its grayscale value
    void drawMap(Picture& pic) {


    }
