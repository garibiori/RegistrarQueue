/**
 * Main file that runs simulation
 * 
 * @author Devin Keller and Ori G
 * @version 1.0
 * @see main.h 
 * 
 */
#include <iostream>
//Allows us to refrence classes in Simulation.h file
#include "Simulation.h"

using namespace std;

int main (int argc, char **argv){
    //Calls Simulation file
    Simulation *sp = new Simulation();
    //Runs processFile in Simulation
    sp->processFile(argv[1]);
    //sp->runSimulation();

    return 0;
}
