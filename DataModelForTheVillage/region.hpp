#include <iostream>
#include <vector>

using namespace std;

struct region
{
    unsigned short int num = 1;

    struct home
    {
        float area = 0;

        struct floor
        {
            bool bedroom = 0;
            bool kitchen = 0;
            bool bathroom = 0;
            bool childrens = 0;
            bool living = 0;
        };

        vector <floor> floors;
    };

    home house;
    float garage = 0;
    float barn = 0;
    float bathhouse = 0;
    float region_area() { return house.area + garage + barn + bathhouse; }


    void input_reg()
    {
        cout << "House:" << endl;
        cout << "Input house area: ";
        cin  >> house.area;

        unsigned short int floors_q;
        cout << "Input floors quantity: ";
        cin  >> floors_q;

        while (floors_q < 1 || floors_q > 3)
        {
            cerr << "Incorrect input!\n";
            cout << "Input floors quantity: ";
            cin  >> floors_q;
        }

        for (char i = 1; i < floors_q + 1; i++)
        {
            cout << "Floor №" << (int)i << endl;
            string answer;
            char sum;

            house.floors.push_back({0, 0, 0, 0, 0});

            do {
                cout << "Will the floor include bedroom?\n";
                cin >> answer;
                if (answer == "yes") house.floors[i].bedroom =    true;
                if (answer == "no")  house.floors[i].bedroom =   false;

                cout << "Will the floor include kitchen?\n";
                cin >> answer;
                if (answer == "yes") house.floors[i].kitchen =    true;
                if (answer == "no")  house.floors[i].kitchen =   false;

                cout << "Will the floor include bathroom?\n";
                cin >> answer;
                if (answer == "yes") house.floors[i].bathroom =   true;
                if (answer == "no")  house.floors[i].bathroom =  false;

                cout << "Will the floor include children's?\n";
                cin >> answer;
                if (answer == "yes") house.floors[i].childrens =  true;
                if (answer == "no")  house.floors[i].childrens = false;

                sum = house.floors[i]. bedroom +
                           house.floors[i]. kitchen +
                           house.floors[i].bathroom +
                           house.floors[i].childrens;
            
                if (sum != 4)
                {
                    cout << "Will the floor include living?\n";
                    cin >> answer;
                    if (answer == "yes") house.floors[i].living =  true;
                    if (answer == "no")  house.floors[i].living = false;
                }
                cout << endl << endl;
            } while (sum < 2);
        }
        do {

            cout <<    "Input garage area: ";
            cin  >>    garage;
            cout <<      "Input barn area: ";
            cin  >>      barn;
            cout << "Input bathhouse area: ";
            cin  >> bathhouse;
            cout << endl << endl;
        } while (garage < 0 || barn < 0 || bathhouse < 0);
        
    }

    void output_reg()
    {
        cout << "Region №" << num << endl << endl;
        cout << "Region area: " << region_area() << " square meters" << endl;
        cout << "House:" << endl;
        cout << "Area: " << house.area << " square meters" << endl;
        
        for (char i = 1; i < house.floors.size(); i++)
        {
            cout << "Floor №" << (int)i << ":\n";

            if (house.floors[i].bedroom)   cout <<    "Bedroom\n";
            if (house.floors[i].kitchen)   cout <<    "Kitchen\n";
            if (house.floors[i].bathroom)  cout <<   "Bathroom\n";
            if (house.floors[i].childrens) cout << "Children's\n";
            if (house.floors[i].living)    cout <<     "Living\n";

        }
        cout << "Garage area: "    << garage    << " square meters\n";
        cout << "Barn area: "      << barn      << " square meters\n";
        cout << "Bathhouse area: " << bathhouse << " square meters\n";
    }
    
};