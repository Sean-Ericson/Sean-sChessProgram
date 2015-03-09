/* 
 * File:   main.cpp
 * Author: Sean
 *
 * Created on February 24, 2015, 4:47 PM
 */

#include <cstdlib>
#include <iostream>
#include "ChessTextInterface.hpp"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) 
{   
    TextInterface interface;
    interface.run();
    
    system("pause");
    return 0;
}

