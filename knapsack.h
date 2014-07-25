/*
 * knapsack.h
 *
 * Copyright 2014 Kevin Tang <ktang@caltech.edu>
 *
 * This file is available under the MIT license. See
 * http://opensource.org/licenses/MIT for more details
 *
 * This is the header file for algorithms that solve the knapsack problem
 * These functions are used to solve an optimization of funds allocated to 
 * maximize the use of DBAL at Caltech. 
 *
 */
#ifndef __knapsack_h__
#define __knapsack_h__

#include <vector>
#include <algorithm>
#include <string>
 
// ******* DATA STRUCTURES ***********

// an item
struct item
{
    int price;
    std::string name;
};


// This struct represents a memoized solution to a subproblem
struct m_elem
{
    int opt_weight;         // maximum weight up to here
    int weight;             // Weight cap of problem
    std::vector<item> items; // vector of selected objects
};

// ******* MAIN CLASS ****************
class KnapSack_DP
{
    int capacity;               // capacity
    std::vector<item> cat;      // selection of available items
    std::vector<m_elem> Ms;     // vector for memoization

public:
    KnapSack_DP(int capacity, std::vector<item> cat);
    ~KnapSack_DP();
    m_elem solve();


    int getCapacity();

};

// ******* HELPER FUNCTIONS **********
bool compareByPrice(item a, item b);
#endif