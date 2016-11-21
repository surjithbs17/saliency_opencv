
#include <opencv2/core/utility.hpp>
#include <opencv2/saliency.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/video/background_segm.hpp>
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



int binwang(int input_threshold)
{
	
	Mat frame;
	Mat image;
    Mat gray_sal;
    Mat threshold_mat;
    Mat fgMaskMOG2;
	Ptr<Saliency> saliencyAlgorithm = Saliency::create( "BinWangApr2014");
	Ptr<BackgroundSubtractor> pMOG2;

  	if( saliencyAlgorithm == NULL )
	{
	    cout << "***Error in the instantiation of the saliency algorithm...***\n";
	    return -1;
	}


	cap >> frame;
	frame.copyTo( image );

	//Ptr<Size> size = Ptr<Size>( new Size( image.cols, image.rows ) );
    saliencyAlgorithm.dynamicCast<MotionSaliencyBinWangApr2014>()->setImagesize( image.cols, image.rows );
    saliencyAlgorithm.dynamicCast<MotionSaliencyBinWangApr2014>()->init();
    pMOG2 = createBackgroundSubtractorMOG2();

    bool paused = false;
    for ( ;; )
    {
      if( !paused )
      {

        cap >> frame;
        cvtColor( frame, frame, COLOR_BGR2GRAY );

        Mat saliencyMap;
        if( saliencyAlgorithm->computeSaliency( frame, saliencyMap ) )
        {
          std::cout << "current frame motion saliency done" << std::endl;
        }

        imshow( "image", frame );
        imshow( "saliencyMap", saliencyMap);
        pMOG2->apply(frame, fgMaskMOG2);

	    saliencyMap.convertTo(gray_sal, -1, 255,0);
	      
	    threshold(gray_sal,threshold_mat,input_threshold,255,THRESH_BINARY);

	    imshow("Threshold Value",threshold_mat);
	    imshow("MOG",fgMaskMOG2);
      }

      char c = (char) waitKey( 2 );
      if( c == 'q' )
        break;
      if( c == 'p' )
        paused = !paused;

    }
}

int saliency_spec(int input_threshold)
{
	  Mat binaryMap;
	  Mat image;
	  Mat frame;
	  Mat threshold_mat;
	  Mat fgMaskMOG2;
	  Mat gray_sal;
	  Ptr<BackgroundSubtractor> pMOG2;

	  Ptr<Saliency> saliencyAlgorithm = Saliency::create( "SPECTRAL_RESIDUAL");

	  if( saliencyAlgorithm == NULL )
	  {
	    cout << "***Error in the instantiation of the saliency algorithm...***\n";
	    return -1;
	  }



	  cap >> frame;
	  pMOG2 = createBackgroundSubtractorMOG2();  



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
	      
	      saliencyMap.convertTo(gray_sal, -1, 255,0);
	      pMOG2->apply(frame, fgMaskMOG2);
	      
	      threshold(gray_sal,threshold_mat,input_threshold,255,THRESH_BINARY);

	      imshow("Threshold Value",threshold_mat);
	      imshow("MOG",fgMaskMOG2);
	      char c = (char) waitKey( 2 );
	      if( c == 'q' )
	        break;
	    }

	    cap >> frame;
	  }
}






int main( int argc, char** argv )
{
  

  video = argv[1];
  String algorithm = argv[2];
  //String threshold_value = argv[3];

  int input_threshold = atoi(argv[3]);
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
  

  //createTrackbar( "Min Threshold:", "Track Bar", &lowThreshold, 255, saliency_spec );  
  if(algorithm.find( "STATIC" ) == 0)
  {
  	saliency_spec(input_threshold);
  }
  
  else if(algorithm.find( "MOTION" ) == 0)
  {
  	binwang(input_threshold);
  }

  

  return 0;
}

