#include "region.hpp"

int main()
{
    cout << "Input regions quantity: ";
    unsigned short int quantity;
    cin >> quantity;

    vector <region> village;
    
    for (unsigned short i = 0; i < quantity; i++)
    {
        region current_region;
        current_region.input_reg();
        village.push_back(current_region);
    }
    
    cout << endl << endl;

    for (unsigned short int i = 0; i < quantity; i++)
    {
        village[i].num = i + 1;
        village[i].output_reg();
        cout << endl << endl;
    }
}