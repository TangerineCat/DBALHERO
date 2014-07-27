#include <assert.h>
#include <iostream>
#include "knapsack.h"

// #define maxcount 10

// ******* DATA STRUCTURES ***********

/* struct for memoizing each M solution as well as containing the selection
 * that creates such solution */


// ******* Class Functions ****************

// Constructor given problem statement. This formalizes the problem statement
KnapSack_DP::KnapSack_DP(int capacity, std::vector<item> cat) : 
    capacity(capacity), 
    cat(cat)
{
    // Sort the pids by increasing price of object
    sort(this->cat.begin(), this->cat.end(), compareByPrice);
}


KnapSack_DP::~KnapSack_DP()
{
    // TODO
}

m_elem KnapSack_DP::solve()
{
    // Check for new solution or not
    if(!this->Ms.empty())
    {
        if(this->Ms.back().weight == capacity)
        {
            return this->Ms.back();
        }
        else
        {
            this->Ms.clear();
        }
    }
    // Initialize base step
    int w;                      // step
    std::vector<item> sol_0;
    m_elem m_0 = {0, 0, 0, sol_0}; // initialize base case
    
    // No item case and not enough money case
    if (cat.size() == 0 || cat[0].price > this->capacity)
    {
        std::cout << "Can't buy anything with " << this->capacity << " cents and "
            << cat.size() << " items" << std::endl;
        m_0.weight = capacity;
        return m_0;
    }

    // All weights smaller than the first weight will have a maximum of 0.
    for (w = 0; w < cat[0].price; w++)
    {
        m_0.weight = w;
        Ms.push_back(m_0); // creates copy so it's fine to keep updating
    }

    int tprice, ttotal, tmax;       // temporary variables for price,
                                    // total, maximum total.
    item itemmax;                   // item that is the maximum.
    m_elem tsol;                    // temporary solution


    for(; w <= this->capacity; w++)    // increase programming table from bottom up
    {
        tmax = Ms[w-1].opt_weight; 


        for(int i = 0; i <= (int) this->cat.size(); i++)   // loop through all item in order
        {
            tprice = cat[i].price;
            if(tprice > w) // no need to consider any items that costs more than the weight.
            {
                break;
            }

            assert(w >= tprice); // make sure that the price not greater than the weight

            ttotal = tprice + Ms[w - tprice].opt_weight;
            if(ttotal > w) // escape if the total goes over
            {
                continue;
            }

            if (ttotal >= tmax)
            {
                tmax  = ttotal;
                itemmax = cat[i];
            }

        }
        assert (tmax <= w); // make sure that the total is less than temp capacity

        tsol.items = Ms[w - itemmax.price].items;
        tsol.items.push_back(itemmax);
        tsol.opt_weight = tmax;
        tsol.weight = w;
        
        Ms.push_back(tsol);
    }

    return Ms.back();
}

int KnapSack_DP::getCapacity()
{
    return this->capacity;
}

/* helper functions */

bool compareByPrice(item a, item b)
{
    return a.price < b.price;
}


