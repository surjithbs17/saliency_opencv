# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/surjith/Downloads/saliencyFineGrained

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/surjith/Downloads/saliencyFineGrained/build

# Include any dependencies generated for this target.
include CMakeFiles/saliencyFineGrained.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/saliencyFineGrained.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/saliencyFineGrained.dir/flags.make

CMakeFiles/saliencyFineGrained.dir/staticSaliencyFineGrained.cpp.o: CMakeFiles/saliencyFineGrained.dir/flags.make
CMakeFiles/saliencyFineGrained.dir/staticSaliencyFineGrained.cpp.o: ../staticSaliencyFineGrained.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/surjith/Downloads/saliencyFineGrained/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/saliencyFineGrained.dir/staticSaliencyFineGrained.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/saliencyFineGrained.dir/staticSaliencyFineGrained.cpp.o -c /home/surjith/Downloads/saliencyFineGrained/staticSaliencyFineGrained.cpp

CMakeFiles/saliencyFineGrained.dir/staticSaliencyFineGrained.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/saliencyFineGrained.dir/staticSaliencyFineGrained.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/surjith/Downloads/saliencyFineGrained/staticSaliencyFineGrained.cpp > CMakeFiles/saliencyFineGrained.dir/staticSaliencyFineGrained.cpp.i

CMakeFiles/saliencyFineGrained.dir/staticSaliencyFineGrained.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/saliencyFineGrained.dir/staticSaliencyFineGrained.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/surjith/Downloads/saliencyFineGrained/staticSaliencyFineGrained.cpp -o CMakeFiles/saliencyFineGrained.dir/staticSaliencyFineGrained.cpp.s

CMakeFiles/saliencyFineGrained.dir/staticSaliencyFineGrained.cpp.o.requires:

.PHONY : CMakeFiles/saliencyFineGrained.dir/staticSaliencyFineGrained.cpp.o.requires

CMakeFiles/saliencyFineGrained.dir/staticSaliencyFineGrained.cpp.o.provides: CMakeFiles/saliencyFineGrained.dir/staticSaliencyFineGrained.cpp.o.requires
	$(MAKE) -f CMakeFiles/saliencyFineGrained.dir/build.make CMakeFiles/saliencyFineGrained.dir/staticSaliencyFineGrained.cpp.o.provides.build
.PHONY : CMakeFiles/saliencyFineGrained.dir/staticSaliencyFineGrained.cpp.o.provides

CMakeFiles/saliencyFineGrained.dir/staticSaliencyFineGrained.cpp.o.provides.build: CMakeFiles/saliencyFineGrained.dir/staticSaliencyFineGrained.cpp.o


CMakeFiles/saliencyFineGrained.dir/main.cpp.o: CMakeFiles/saliencyFineGrained.dir/flags.make
CMakeFiles/saliencyFineGrained.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/surjith/Downloads/saliencyFineGrained/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/saliencyFineGrained.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/saliencyFineGrained.dir/main.cpp.o -c /home/surjith/Downloads/saliencyFineGrained/main.cpp

CMakeFiles/saliencyFineGrained.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/saliencyFineGrained.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/surjith/Downloads/saliencyFineGrained/main.cpp > CMakeFiles/saliencyFineGrained.dir/main.cpp.i

CMakeFiles/saliencyFineGrained.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/saliencyFineGrained.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/surjith/Downloads/saliencyFineGrained/main.cpp -o CMakeFiles/saliencyFineGrained.dir/main.cpp.s

CMakeFiles/saliencyFineGrained.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/saliencyFineGrained.dir/main.cpp.o.requires

CMakeFiles/saliencyFineGrained.dir/main.cpp.o.provides: CMakeFiles/saliencyFineGrained.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/saliencyFineGrained.dir/build.make CMakeFiles/saliencyFineGrained.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/saliencyFineGrained.dir/main.cpp.o.provides

CMakeFiles/saliencyFineGrained.dir/main.cpp.o.provides.build: CMakeFiles/saliencyFineGrained.dir/main.cpp.o


# Object files for target saliencyFineGrained
saliencyFineGrained_OBJECTS = \
"CMakeFiles/saliencyFineGrained.dir/staticSaliencyFineGrained.cpp.o" \
"CMakeFiles/saliencyFineGrained.dir/main.cpp.o"

# External object files for target saliencyFineGrained
saliencyFineGrained_EXTERNAL_OBJECTS =

saliencyFineGrained: CMakeFiles/saliencyFineGrained.dir/staticSaliencyFineGrained.cpp.o
saliencyFineGrained: CMakeFiles/saliencyFineGrained.dir/main.cpp.o
saliencyFineGrained: CMakeFiles/saliencyFineGrained.dir/build.make
saliencyFineGrained: /usr/local/lib/libopencv_stitching.so.3.1.0
saliencyFineGrained: /usr/local/lib/libopencv_superres.so.3.1.0
saliencyFineGrained: /usr/local/lib/libopencv_videostab.so.3.1.0
saliencyFineGrained: /usr/local/lib/libopencv_aruco.so.3.1.0
saliencyFineGrained: /usr/local/lib/libopencv_bgsegm.so.3.1.0
saliencyFineGrained: /usr/local/lib/libopencv_bioinspired.so.3.1.0
saliencyFineGrained: /usr/local/lib/libopencv_ccalib.so.3.1.0
saliencyFineGrained: /usr/local/lib/libopencv_dnn.so.3.1.0
saliencyFineGrained: /usr/local/lib/libopencv_dpm.so.3.1.0
saliencyFineGrained: /usr/local/lib/libopencv_fuzzy.so.3.1.0
saliencyFineGrained: /usr/local/lib/libopencv_hdf.so.3.1.0
saliencyFineGrained: /usr/local/lib/libopencv_line_descriptor.so.3.1.0
saliencyFineGrained: /usr/local/lib/libopencv_optflow.so.3.1.0
saliencyFineGrained: /usr/local/lib/libopencv_plot.so.3.1.0
saliencyFineGrained: /usr/local/lib/libopencv_reg.so.3.1.0
saliencyFineGrained: /usr/local/lib/libopencv_saliency.so.3.1.0
saliencyFineGrained: /usr/local/lib/libopencv_stereo.so.3.1.0
saliencyFineGrained: /usr/local/lib/libopencv_structured_light.so.3.1.0
saliencyFineGrained: /usr/local/lib/libopencv_surface_matching.so.3.1.0
saliencyFineGrained: /usr/local/lib/libopencv_tracking.so.3.1.0
saliencyFineGrained: /usr/local/lib/libopencv_xfeatures2d.so.3.1.0
saliencyFineGrained: /usr/local/lib/libopencv_ximgproc.so.3.1.0
saliencyFineGrained: /usr/local/lib/libopencv_xobjdetect.so.3.1.0
saliencyFineGrained: /usr/local/lib/libopencv_xphoto.so.3.1.0
saliencyFineGrained: /usr/local/lib/libopencv_shape.so.3.1.0
saliencyFineGrained: /usr/local/lib/libopencv_rgbd.so.3.1.0
saliencyFineGrained: /usr/local/lib/libopencv_calib3d.so.3.1.0
saliencyFineGrained: /usr/local/lib/libopencv_video.so.3.1.0
saliencyFineGrained: /usr/local/lib/libopencv_datasets.so.3.1.0
saliencyFineGrained: /usr/local/lib/libopencv_face.so.3.1.0
saliencyFineGrained: /usr/local/lib/libopencv_text.so.3.1.0
saliencyFineGrained: /usr/local/lib/libopencv_features2d.so.3.1.0
saliencyFineGrained: /usr/local/lib/libopencv_flann.so.3.1.0
saliencyFineGrained: /usr/local/lib/libopencv_objdetect.so.3.1.0
saliencyFineGrained: /usr/local/lib/libopencv_ml.so.3.1.0
saliencyFineGrained: /usr/local/lib/libopencv_highgui.so.3.1.0
saliencyFineGrained: /usr/local/lib/libopencv_photo.so.3.1.0
saliencyFineGrained: /usr/local/lib/libopencv_videoio.so.3.1.0
saliencyFineGrained: /usr/local/lib/libopencv_imgcodecs.so.3.1.0
saliencyFineGrained: /usr/local/lib/libopencv_imgproc.so.3.1.0
saliencyFineGrained: /usr/local/lib/libopencv_core.so.3.1.0
saliencyFineGrained: CMakeFiles/saliencyFineGrained.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/surjith/Downloads/saliencyFineGrained/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable saliencyFineGrained"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/saliencyFineGrained.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/saliencyFineGrained.dir/build: saliencyFineGrained

.PHONY : CMakeFiles/saliencyFineGrained.dir/build

CMakeFiles/saliencyFineGrained.dir/requires: CMakeFiles/saliencyFineGrained.dir/staticSaliencyFineGrained.cpp.o.requires
CMakeFiles/saliencyFineGrained.dir/requires: CMakeFiles/saliencyFineGrained.dir/main.cpp.o.requires

.PHONY : CMakeFiles/saliencyFineGrained.dir/requires

CMakeFiles/saliencyFineGrained.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/saliencyFineGrained.dir/cmake_clean.cmake
.PHONY : CMakeFiles/saliencyFineGrained.dir/clean

CMakeFiles/saliencyFineGrained.dir/depend:
	cd /home/surjith/Downloads/saliencyFineGrained/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/surjith/Downloads/saliencyFineGrained /home/surjith/Downloads/saliencyFineGrained /home/surjith/Downloads/saliencyFineGrained/build /home/surjith/Downloads/saliencyFineGrained/build /home/surjith/Downloads/saliencyFineGrained/build/CMakeFiles/saliencyFineGrained.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/saliencyFineGrained.dir/depend

