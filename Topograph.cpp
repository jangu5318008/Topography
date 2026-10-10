#include "picture.h"
#include "Topograph.h"
#include <iostream>
#include <fstream>
using namespace std;



    ///**************Part 1********************************
    ///Constructor.  Open a ArcGIS ASCII Grid file
    ///read the header to assign height and width
    ///resize v and read elevation data

/*
ncols        2503
nrows        996
xllcorner    -76.004991680283
yllcorner    41.305829917667
cellsize     0.000277777800
NODATA_value  -999999
*/


    Topograph::Topograph(string fileName) {
        //v(fileName); 

        string rowz, colz;
        ifstream ifs(fileName);
        if (!ifs.is_open()) {
            cout << "File cannot be opened" << endl;
            return;
        }

        ifs >> rowz >> width >> colz >> height; 


        v.resize(height); 
        for (int i = 0; i < height; i++) {
            v[i].resize(width, 0.0) ;
        }
            string shred;
            double discard;      
        for (int i = 0; i < 4; i++) {
            ifs >> shred >> discard;
        }


        for (int j = 0; j < height; j++) {
            for (int i = 0; i < width; i++) {
                ifs >> v[j][i];
            }
        }
/*
        findMin(); 
        findMax(); 
        cout << min << endl; 
        cout << max;
*/


    }


    void Topograph::findMin() {
        min = v[0][0]; 
        for (int j = 0; j < height; j++) {
            for (int i = 0; i < width; i++) {
                if ((v[j][i]) < min) {
                    min = v[j][i];
                }
            }
        }
    }



    void Topograph::findMax() {
        max = v[0][0]; 
        for (int j = 0; j < height; j++) {
            for (int i = 0; i < width; i++) {
                if ((v[j][i]) > max) {
                    max = v[j][i];
                }
            }
        }
    }

    double Topograph::mapRange(double n, double fromLow, double fromHigh, double toLow, double toHigh) {




}

/*
                Matrix::Matrix(int _rows, int _cols) {
                rows = _rows;
                cols = _cols; 
                a.resize(rows); 
                for (int i = 0; i < rows; i++) {
                   //(newSize, desiredValue) 
                   a[i].resize(cols, 0.0);
                    
                }
 
            }

*/





    ///find min and max elevation values
    ///call mapRange to convert each elevation to grayscale
    ///set each Picture coordinate at (x,y) to its grayscale value
    void Topograph::drawMap(Picture& pic) {


    }
   
    
/*
    private:
    void findMin();
    void findMax();
    ///scale n from [fromLow:fromHigh] to [toLow:toHigh]
    double mapRange(double n, double fromLow, double fromHigh, double toLow, double toHigh);

    vector<vector<double>> v;
    int height;
    int width;
    double min;
    double max;


*/