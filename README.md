# saliency_opencv
Reusing the OpenCV's Saliency algorithms for research purpose

Directions to install OpenCV 3.1.0 with OpenCV_contrib modules

- Do this step by step
1. sudo apt-get install build-essential
2. sudo apt-get install cmake git libgtk2.0-dev pkg-config libavcodec-dev libavformat-dev libswscale-dev
3. sudo apt-get install python-dev python-numpy libtbb2 libtbb-dev libjpeg-dev libpng-dev libtiff-dev libjasper-dev libdc1394-22-dev
4. git clone https://github.com/Itseez/opencv.git
5. git clone https://github.com/Itseez/opencv_contrib.git
6. cd opencv
7. mkdir release
8. cmake -D CMAKE_BUILD_TYPE=RELEASE -D CMAKE_INSTALL_PREFIX=/usr/local -D OPENCV_EXTRA_MODULES_PATH=source_directory/opencv_contrib/modules source_directory/opencv/
9. make -j6
10. sudo make install

Check the installation by typing the following command

pkg-config --modversion opencv

This should show the version of your openCV. Hopefully 3.1.0.

Lets try out the Saliency Example now. Clone this directory 

1. git clone https://github.com/surjithbs17/saliency_opencv.git
2. git checkout test

Make the file using CMAKE

1. type 'cmake-gui'
2. Select the source code directory as "saliency_opencv"
3. Select the Build directory as "saliency_opencv/build"
4. Click "Configure" and "Generate"
5. Go to the build directory using "cd saliency_opencv/build"
6. type "make all"
7. Execute the code by typing "./saliencyFineGrained BinWangApr2014 airplane.mp4 10"

This should show two outputs(Video Frame in Grayscale and saliency map.

Reference: 

1. http://embedonix.com/articles/image-processing/installing-opencv-3-1-0-on-ubuntu/

2. http://www.samontab.com/web/saliency/

3. http://docs.opencv.org/3.0-beta/modules/saliency/doc/saliency.html

4. http://docs.opencv.org/3.1.0/d9/dcd/classcv_1_1saliency_1_1Saliency.html
