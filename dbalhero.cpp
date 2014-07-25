/* DBALHERO.cpp 
 *
 */

#include "dbalhero.h"

void usage()
{
    std::cerr << "usage: ./dbalhero [amount USD in cents]" << std::endl;
    exit(-1);
}

std::vector<std::string> getLineAndSplit(std::ifstream& str)
{
    std::vector<std::string>   result;
    std::string                line;
    std::getline(str,line);

    std::stringstream          lineStream(line);
    std::string                cell;

    while(std::getline(lineStream,cell,','))
    {
        result.push_back(cell);
    }
    return result;
}

void readinCSV(std::vector<item>& list, std::string filename)
{
    std::string value;
    std::ifstream catstream(filename);
    std::vector<std::string> line;
    std::string temp;
    if(!catstream.is_open())
    {
        std::cerr << "Unable to open file" << std::endl;
        return;
    }

    while(catstream.good())
    {
        item newitem = {}; 
        line = getLineAndSplit(catstream);

        newitem.name = line[0];

        std::stringstream lineStream(line[1]);
        std::getline(lineStream, temp, '.');
        newitem.price = stoi(temp) * 100;
        std::getline(lineStream, temp);
        newitem.price += stoi(temp);
        /*)
        newitem.taxp = stoi(line[2]);

        newitem.candy = !line[3].empty();
        newitem.drink = !line[4].empty();

        if(!line[5].empty()){newitem.fridge = 2;}
        else if(!line[6].empty()){newitem.fridge = 1;}
        else {newitem.fridge = 0;}
        */

        list.push_back(newitem);

    }
}

int main(int argc, char** argv) 
{
    int budget;
    if (argc == 2) 
    {
        budget = atoi(argv[1]);
    }
    else { 
        std::cout << "incorrect number of arguments" << std::endl;
        usage();
    }

    std::vector<item> itemlist;
    readinCSV(itemlist, "cstoredatabase.csv");

    //while(1)
    //{
    if (budget == 0)
    {
        return 0;
    }
    KnapSack_DP change_calculator(budget, itemlist);
    m_elem ans = change_calculator.solve();

    for(unsigned int i = 0; i < ans.items.size(); i++)
    {
        std::cout << ans.items[i].name << ", " << std::endl;
    } 


    //    cin >> budget;
    //}
    return 0;
}
