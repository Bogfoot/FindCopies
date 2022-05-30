###############
##  Project  ##
###############

cmake_minimum_required(VERSION 3.18)

project(
  "FindCopies" # This will exposed as the variable PROJECT_NAME.
  VERSION 0.1.0 # Used for installation and defines variables PROJECT_VERSION_MAJOR, PROJECT_VERSION_MINOR, PROJECT_VERSION_PATCH, and PROJECT_VERSION_TWEAK.
  LANGUAGES CXX # Used to determine the languages to use based on file extensions
)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
add_definitions("-Wall -lstdc++fs")
############################
##  Modules and scripts   ##
############################

# Standard CMake modules

include(InstallRequiredSystemLibraries) # Tell CMake that the `install` target needs to install required system libraries (eg: Windows SDK)
include(CMakePackageConfigHelpers)      # Helper to create relocatable packages

#==========================#
#  BoilerPlate executable  #
#==========================#

# Always list the source files explicitly, including headers so that they are listed in the IDE
# If you need to use files based on a variable value, use target_sources
add_executable(
  ${PROJECT_NAME}
  src/main.cpp
  # src/main.h
  src/Walk.cpp
  # src/Walk.h
)
#=========================#
#               Target link libraries #
#=========================#

#target_link_libraries(${PROJECT_NAME} PRIVATE glad::glad)

# If you need platform specific files to be compiled and do not want to add a new target for this,
# you can use target_sources instead. Note that configuration-dependent sources are not supported yet (see https://gitlab.kitware.com/cmake/cmake/issues/18233)

# target_compile_features(${PROJECT_NAME} PRIVATE lstdc++fs)
