# Specify the minimum CMAKE version required
CMAKE_MINIMUM_REQUIRED(VERSION 3.7)

PROJECT(gsl-extra VERSION 0.0.3)


# Set output directories
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/../lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/../lib")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/../bin")


# OS specific variables
if(APPLE)
    SET(CMAKE_CXX_FLAGS "-Wimplicit-function-declaration")
    SET(OS_INCLUDE_DIRS "/usr/include" "/usr/local/include" "/opt/homebrew/include")
    SET(OS_LIB_DIRS "/usr/lib" "/usr/local/lib" "/opt/homebrew/lib")
elseif(UNIX)
    SET(CMAKE_CXX_FLAGS "-Wimplicit-function-declaration")
    SET(OS_INCLUDE_DIRS "/usr/include" "/usr/local/include")
    SET(OS_LIB_DIRS "/usr/lib" "/usr/local/lib")
elseif(WIN32)
    SET(CMAKE_CXX_FLAGS "-Wimplicit-function-declaration")
    SET(OS_INCLUDE_DIRS "c:/msys2/mingw64/include")
    SET(OS_INCLUDE_DIRS "c:/msys2/mingw64/lib")      
endif()

INCLUDE_DIRECTORIES("${CMAKE_BINARY_DIR}/../include" ${OS_INCLUDE_DIRS})
LINK_DIRECTORIES("${CMAKE_BINARY_DIR}/../lib" ${OS_LIB_DIRS})


# Source related variables
SET(TENSOR3_SRC
    src/gsl_tensor3.c
    src/gsl_tensor3_long_double.c        
)
SET(M_LDOUBLE_SRC
    src/gsl_tensor3_long_double.c          
)

# Build the library
ADD_LIBRARY(gsl-extra STATIC ${TENSOR3_SRC} ${M_LDOUBLE_SRC})
