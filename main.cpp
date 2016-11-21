
#include <opencv2/core/utility.hpp>
#include <opencv2/saliency.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

using namespace std;
using namespace cv;
using namespace saliency;


int lowThreshold;
int const max_lowThreshold = 100;

/*
static const char* keys =
{ "{@saliency_algorithm | | Saliency algorithm <saliencyAlgorithmType.[saliencyAlgorithmTypeSubType]> }"
    "{@video_name      | | video name            }"
    "{@start_frame     |1| Start frame           }"
    "{@training_path   |1| Path of the folder containing the trained files}" };

static void help()
{
  cout << "\nThis example shows the functionality of \"Saliency \""
       "Call:\n"
       "./example_saliency_computeSaliency <saliencyAlgorithmSubType> <video_name> <start_frame> \n"
       << endl;
}
*/

VideoCapture cap;
String video;
Ptr<Saliency> saliencyAlgorithm;


void saliency_spec(int input_threshold)
{
	  Mat binaryMap;
	  Mat image;
	  Mat frame;
	  Mat threshold_mat;
	  cap >> frame;
	  while (!frame.empty())
	  {
	  	
	  	frame.copyTo( image );
	  	Mat saliencyMap;
	  	

	  	if( saliencyAlgorithm->computeSaliency( image, saliencyMap ) )
	    {
	      StaticSaliencySpectralResidual spec;
	      spec.computeBinaryMap( saliencyMap, binaryMap );

	      imshow( "Saliency Map", saliencyMap );
	      imshow( "Original Image", image );
	      imshow( "Binary Map", binaryMap );
	      threshold( binaryMap, threshold_mat, input_threshold, 255,0);
	      Mat gray_sal;
	      saliencyMap.convertTo(gray_sal, -1, 255,0);
	      //adaptiveThreshold(gray_sal, threshold_mat, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, 7, 0);
	      //double norm = input_threshold/255;
	      
	      threshold(gray_sal,threshold_mat,input_threshold,255,THRESH_BINARY);

	      //cout << "M = "<< endl << " "  << threshold_mat << endl << endl;
	      double min, max;
		  cv::minMaxLoc(gray_sal, &min, &max);

		  cout << "MAX" << max << "MIN" << min << "Thresh " << input_threshold << endl;
	      cout<< "After Adaptive" <<endl;

	      imshow("Threshold Value",threshold_mat);
	      char c = (char) waitKey( 0 );
	      if( c == 'q' )
	        break;
	    }

	    cap >> frame;
	  }
}






int main( int argc, char** argv )
{
  

  video = argv[1];
  String threshold_value = argv[2];

  int input_threshold = atoi(argv[2]);
  cout << video  << " "<<input_threshold  << endl;
  //int start_frame = parser.get<int>( 2 );
  //String training_path = parser.get<String>( 3 );

  if(video.empty() )
  {
    return -1;
  }

  //open the capture
  //VideoCapture cap;
  cap.open( video );
  //cap.set( CAP_PROP_POS_FRAMES, start_frame );

  if( !cap.isOpened() )
  {
    
    cout << "***Could not initialize capturing...***\n";
    cout << "Current parameter's value: \n";
    //parser.printMessage();
    return -1;
  }

 

  //instantiates the specific Saliency
  saliencyAlgorithm = Saliency::create( "SPECTRAL_RESIDUAL");

  if( saliencyAlgorithm == NULL )
  {
    cout << "***Error in the instantiation of the saliency algorithm...***\n";
    return -1;
  }

  //createTrackbar( "Min Threshold:", "Track Bar", &lowThreshold, 255, saliency_spec );  
  saliency_spec(input_threshold);
  

  return 0;
}
