/*
Peter Nguyen
Last Updated: 9/20/21
FibLFSR.h: Header file with declarations. Implementation
           in FibLFSR.cpp
*/

#ifndef FIBLFSR_H
#define FIBLFSR_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class FibLFSR
{
    public: 
        FibLFSR(string seed);

        int step();

        int generate(int k);

        friend ostream& operator<<(ostream& out, const FibLFSR& obj);

    private:
        vector<int> seed_data;
};

#endif
