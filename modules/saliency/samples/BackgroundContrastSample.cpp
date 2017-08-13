// This file is part of OpenCV project.
// It is subject to the license terms in the LICENSE file found in the top-level directory
// of this distribution and at http://opencv.org/license.html.


#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/saliency.hpp>
#include <opencv2/ximgproc.hpp>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;
using namespace cv;
using namespace saliency;


int main(int argc, char* argv[])
{
    const char *keys =
            "{ help h usage ?    |     | show this message }"
    		"{ img_path          |     | path to img }"
    		"{ foregroundImg_path|     | path to saliency img generated by other method }"
    		"{ optimization      |0    | 0 for aggregated optimized with no outside saliency, 1 for optimizaed with outside saliency }";

    CommandLineParser parser(argc, argv, keys);
    if (parser.has("help"))
    {
        parser.printMessage();
        return 0;
    }
    string img_path = parser.get<string>("img_path");
    string foregroundImg_path = parser.get<string>("foregroundImg_path");

    Mat img = imread(img_path);
    Mat fgImg = imread(foregroundImg_path);
    BackgroundContrast bc;
    if ( parser.get<bool>( "optimization" ) )
    {
        bc.saliencyMapVisualize(bc.saliencyMapGenerator(img, fgImg, 1), 0);
    }
    else
    {
    	bc.saliencyMapVisualize(bc.saliencyMapGenerator(img), 0);
    }
    return 0;
} //main
