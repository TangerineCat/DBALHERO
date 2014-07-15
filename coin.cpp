#include "knapsack.h"

#include <iostream>

using namespace std;

void usage()
{
    cerr << "usage: ./coin [amount USD in cents]" << endl;
    exit(-1);
}

int main(int argc, char** argv) 
{
    int budget;
    if (argc == 2) 
    {
        budget = atoi(argv[1]);
    }
    else { 
        cout << "incorrect number of arguments" << endl;
        usage();
    }

    vector<item> coins = 
    {
        {1,     "penny"}, 
        {5,     "nickel"},
        {10,    "dime"},
        {25,    "quarter"},
        {100,   "dollar"},
        {500,   "five dollars"},
        {1000,  "ten dollars"},
        {2000,  "twenty dollars"},
        {5000,  "fifty dollar bill"},
        {10000, "benjamin"}
    };

    //while(1)
    //{
    if (budget == 0)
    {
        return 0;
    }
    KnapSack_DP change_calculator(budget, coins);
    m_elem ans = change_calculator.solve();

    for(unsigned int i = 0; i < ans.items.size(); i++)
    {
        cout << ans.items[i].name << ", " << endl;
    } 

    //    cin >> budget;
    //}
    return 0;
}
