# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.14

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\CLion 2019.2.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\CLion 2019.2.2\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Dani\CLionProjects\DamasEsp_Sabbagh_Daniel

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Dani\CLionProjects\DamasEsp_Sabbagh_Daniel\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/DamasEsp_Sabbagh_Daniel.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/DamasEsp_Sabbagh_Daniel.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/DamasEsp_Sabbagh_Daniel.dir/flags.make

CMakeFiles/DamasEsp_Sabbagh_Daniel.dir/main.cpp.obj: CMakeFiles/DamasEsp_Sabbagh_Daniel.dir/flags.make
CMakeFiles/DamasEsp_Sabbagh_Daniel.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Dani\CLionProjects\DamasEsp_Sabbagh_Daniel\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/DamasEsp_Sabbagh_Daniel.dir/main.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\DamasEsp_Sabbagh_Daniel.dir\main.cpp.obj -c C:\Users\Dani\CLionProjects\DamasEsp_Sabbagh_Daniel\main.cpp

CMakeFiles/DamasEsp_Sabbagh_Daniel.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DamasEsp_Sabbagh_Daniel.dir/main.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Dani\CLionProjects\DamasEsp_Sabbagh_Daniel\main.cpp > CMakeFiles\DamasEsp_Sabbagh_Daniel.dir\main.cpp.i

CMakeFiles/DamasEsp_Sabbagh_Daniel.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DamasEsp_Sabbagh_Daniel.dir/main.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Dani\CLionProjects\DamasEsp_Sabbagh_Daniel\main.cpp -o CMakeFiles\DamasEsp_Sabbagh_Daniel.dir\main.cpp.s

# Object files for target DamasEsp_Sabbagh_Daniel
DamasEsp_Sabbagh_Daniel_OBJECTS = \
"CMakeFiles/DamasEsp_Sabbagh_Daniel.dir/main.cpp.obj"

# External object files for target DamasEsp_Sabbagh_Daniel
DamasEsp_Sabbagh_Daniel_EXTERNAL_OBJECTS =

DamasEsp_Sabbagh_Daniel.exe: CMakeFiles/DamasEsp_Sabbagh_Daniel.dir/main.cpp.obj
DamasEsp_Sabbagh_Daniel.exe: CMakeFiles/DamasEsp_Sabbagh_Daniel.dir/build.make
DamasEsp_Sabbagh_Daniel.exe: CMakeFiles/DamasEsp_Sabbagh_Daniel.dir/linklibs.rsp
DamasEsp_Sabbagh_Daniel.exe: CMakeFiles/DamasEsp_Sabbagh_Daniel.dir/objects1.rsp
DamasEsp_Sabbagh_Daniel.exe: CMakeFiles/DamasEsp_Sabbagh_Daniel.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Dani\CLionProjects\DamasEsp_Sabbagh_Daniel\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable DamasEsp_Sabbagh_Daniel.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\DamasEsp_Sabbagh_Daniel.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/DamasEsp_Sabbagh_Daniel.dir/build: DamasEsp_Sabbagh_Daniel.exe

.PHONY : CMakeFiles/DamasEsp_Sabbagh_Daniel.dir/build

CMakeFiles/DamasEsp_Sabbagh_Daniel.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\DamasEsp_Sabbagh_Daniel.dir\cmake_clean.cmake
.PHONY : CMakeFiles/DamasEsp_Sabbagh_Daniel.dir/clean

CMakeFiles/DamasEsp_Sabbagh_Daniel.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Dani\CLionProjects\DamasEsp_Sabbagh_Daniel C:\Users\Dani\CLionProjects\DamasEsp_Sabbagh_Daniel C:\Users\Dani\CLionProjects\DamasEsp_Sabbagh_Daniel\cmake-build-debug C:\Users\Dani\CLionProjects\DamasEsp_Sabbagh_Daniel\cmake-build-debug C:\Users\Dani\CLionProjects\DamasEsp_Sabbagh_Daniel\cmake-build-debug\CMakeFiles\DamasEsp_Sabbagh_Daniel.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/DamasEsp_Sabbagh_Daniel.dir/depend

