#include "picture.h"
#include "Topograph.h"
#include <iostream>
#include <fstream>
using namespace std;


/*
ncols        2503
nrows        996
xllcorner    -76.004991680283
yllcorner    41.305829917667
cellsize     0.000277777800
NODATA_value  -999999
*/


    Topograph::Topograph(string fileName) {


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
        
        return (((n - fromLow)/(fromHigh - fromLow)) * (toHigh - toLow)) + toLow; 

}

    void Topograph::drawMap(Picture& pic) {
        findMin();
        findMax();  
 

        for (int j = 0; j < height; j++) {
            for (int i = 0; i < width; i++) {

                double n = v[j][i];
                double map = mapRange(n, min, max, 0, 255);
                pic.set(i , j, map, map, map);
            }


        }



    }
   
/*

    Create a Picture object from the provided source files, 
    assign each grayscale pixel value to correspond to each elevation value, 
    and then write the Picture object to a file.  
    You should then see a beautiful topographic image.

*/



    
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