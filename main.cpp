
#include <opencv2/core/utility.hpp>
#include <opencv2/saliency.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/video/background_segm.hpp>
#include <iostream>
#include <opencv2/imgcodecs/imgcodecs.hpp>
#include <opencv2/videoio/videoio.hpp>
//#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
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
VideoWriter saliency_video;
VideoWriter saliency_thresh_video;

Mat roi;
Mat merged_frame;


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

    //bool paused = false;
    int frameCnt = cap.get(CV_CAP_PROP_FRAME_COUNT);

      cout << "frame Count "<< frameCnt;
      int count = 0;
    while(!frame.empty())
    {
      
        count++;
        frame.copyTo( image );
        
        cvtColor( image, image, COLOR_BGR2GRAY );

        Mat saliencyMap;
        if( saliencyAlgorithm->computeSaliency( image, saliencyMap ) )
        {
          std::cout << "current frame motion saliency done" << std::endl;
        }

        //imshow( "image", image );
        //imshow( "saliencyMap", saliencyMap);
        pMOG2->apply(image, fgMaskMOG2);

        saliencyMap.convertTo(gray_sal, -1, 255,0);
          
        //threshold(gray_sal,saliencyMap,input_threshold,255,THRESH_BINARY);


        char* filename1;
        char* filename2;
        filename1 = (char *)malloc(100*sizeof(char));
        filename2 = (char *)malloc(100*sizeof(char));
        memset(filename1,'\0',sizeof(filename1));
        memset(filename2,'\0',sizeof(filename2));
        sprintf(filename1,"/home/surjith/cv_research/saliency_opencv/output_video/sal_thresh_motion_%d.jpg",count);
        sprintf(filename2,"/home/surjith/cv_research/saliency_opencv/output_video/sal_mog_motion_%d.jpg",count);
        //cout << filename <<endl;
        imwrite(filename1,saliencyMap);
        imwrite(filename2,fgMaskMOG2);

        //imshow("Threshold Value",threshold_mat);
        //imshow("MOG",fgMaskMOG2);
        //saliency_thresh_video << gray_sal;
        //saliency_video << saliencyMap;
        
        cap >> frame;
 

      

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

      int frameCnt = cap.get(CV_CAP_PROP_FRAME_COUNT);

      cout << "frame Count "<< frameCnt;
      int count = 0;
      while (!frame.empty())
      {
        count++;
        frame.copyTo( image );
        Mat saliencyMap;
        
        cout << count <<endl;

        if( saliencyAlgorithm->computeSaliency( image, saliencyMap ) )
        {
          cout << 0 <<endl;
          StaticSaliencySpectralResidual spec;
          imshow("Saliency Map",saliencyMap);
          
          //spec.computeBinaryMap( saliencyMap, binaryMap );

          //imshow( "Saliency Map", saliencyMap );
          //imshow( "Original Image", image );
          //imshow( "Binary Map", binaryMap );
          
          threshold( saliencyMap, threshold_mat, input_threshold, 255,0);
          
          saliencyMap.convertTo(gray_sal, -1, 255,0);
          pMOG2->apply(image, fgMaskMOG2);
          
          threshold(gray_sal,threshold_mat,input_threshold,255,THRESH_BINARY);
          cout << "After imshow" <<endl;
          //saliency_video << saliencyMap;
          //saliency_thresh_video << fgMaskMOG2;
          char* filename1;
          char* filename2;
          filename1 = (char *)malloc(100*sizeof(char));
          filename2 = (char *)malloc(100*sizeof(char));
          memset(filename1,'\0',sizeof(filename1));
          memset(filename2,'\0',sizeof(filename2));
          sprintf(filename1,"/home/surjith/cv_research/saliency_opencv/output_video/sal_thresh_static_%d.jpg",count);
          sprintf(filename2,"/home/surjith/cv_research/saliency_opencv/output_video/sal_mog_static_%d.jpg",count);
          //cout << filename <<endl;
          imwrite(filename1,threshold_mat);
          imwrite(filename2,fgMaskMOG2);


            
            


            //imshow("Merged Image",merged_frame);




          imshow("Threshold Value",threshold_mat);
          imshow("MOG",fgMaskMOG2);

          imwrite("merged_frame.jpg",merged_frame);
          char c = (char) waitKey( 2 );
      if( c == 'q' )
        break;

          
        }
        printf("Checking seg\n");
        cap >> frame;
        printf("After cap\n");
      }

      printf("After While loop\n");
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
  char* saliency_vid_name,saliency_thresh_vid_name;
  //sprintf(saliency_vid_name,"sal_out_%s",algorithm);
  //sprintf(saliency_thresh_vid_name,"sal_thresh_out_%d",input_threshold);

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
  Size S = Size((int) cap.get(CV_CAP_PROP_FRAME_WIDTH),    // Acquire input size
                  (int) cap.get(CV_CAP_PROP_FRAME_HEIGHT));
  int ex = static_cast<int>(cap.get(CV_CAP_PROP_FOURCC));
   //saliency_video.open("/home/surjith/cv_research/saliency_opencv/output_video/sal_video.mp4",ex,cap.get(CV_CAP_PROP_FPS),S,true);
   //saliency_thresh_video.open("/home/surjith/cv_research/saliency_opencv/output_video/saliency_thresh_vid.mp4",ex,cap.get(CV_CAP_PROP_FPS),S,false);
 

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

  
}

