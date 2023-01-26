/*
Peter Nguyen
Last Updated: 9/20/21
FibLFSR.cpp: Implementation file of a class that uses
a vector to represent a register. Has step() and 
generate() functions to simulate the process of using
XOR on tap bits and shifting register left.
*/
#include "FibLFSR.h"
#include <string>
#include <vector>
#include <iostream>
#include <stdexcept>

using namespace std;

//Constructor
FibLFSR::FibLFSR(string seed){
    if (seed.size()!=16)
        throw invalid_argument("Seed requires 16 bits!");
    seed_data.resize(seed.size());
    //Copy each character of seed into int vector
    for (int i=0; i<seed.size(); i++){
        if (seed.at(i)=='1')
            seed_data[i]=1;
        else 
            seed_data[i]=0;
    }
}

//<< operator overload to display whats in seed_data
ostream& operator<<(ostream& out, const FibLFSR& obj)
{
    for (int i:obj.seed_data)
        out<<i;
    out<<" ";
    return out;
}

//Simulates a step, xor tap bits and add output to end
int FibLFSR::step()
{
    //Xor the tap bits in order
    int output=seed_data[0];
    if (output!=seed_data[2])
        output=1;
    else output=0;
    if (seed_data[3]!=output)
        output=1;
    else output=0;
    if (seed_data[5]!=output)
        output=1;
    else output=0;

    //erase element at begin() and add output to end
    //shifting everything to the left
    seed_data.erase(seed_data.begin());
    seed_data.push_back(output);

    return output;
}

//simulates k number of steps and returns the decimal
//value of the bits extracted from step()
int FibLFSR::generate(int k)
{
    //Test for a positive argument
    if (k < 0) 
        throw invalid_argument("k can't be < 0!");
    int total=0;
    //Run step() k times
    for (int i=0;i<k;i++)
    {
        total=total*2;
        total+=step();
    }

    return total;
}
