/* DBALHERO.h 
 *
 */

#ifndef __dbalhero_h__
#define __dbalhero_h__

#include "knapsack.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <new>

struct csitem : item
{
    int     taxp;   // Percent tax
    int     type;   // 0: food, 1: medicine, 2: consumables, 3: other
    bool    candy;  //
    bool    drink;  //
    int     fridge; // 0 for not, 1 for fridge, 2 for freezer, 3 for N/A
    int     vege;   // 0 for not, 1 for vegetarian, 2 for vegan, 3 for N/A
};


void readinCSV(std::vector<csitem>& list, std::string filename);

#endif