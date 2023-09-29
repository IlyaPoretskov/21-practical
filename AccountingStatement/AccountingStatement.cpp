#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


struct person {
    string name;
    string surname;
    string date;
    int sum;
};


int main() {

    string command;

    cout << "Input command: ";
    cin >> command;


    while (command != "list" && command != "add")
    {
        cerr << "Incorrect command!\n";
        cout << "Input command: ";
        cin >> command;
    }


    if (command == "list")
    {
        vector <person> vec(20);

        ifstream file("People.txt");

        int count = 0;

        while (!file.eof())
        {
            file >> vec[count].name >> vec[count].surname >> vec[count].date >> vec[count].sum;

            count++;
        }
        file.close();

        for (int i = 0; i < count - 1; i++)
        {
            cout << vec[i].name <<  " " << vec[i].surname << " " << vec[i].date << " " << vec[i].sum << endl;
        }
    }



    else if (command == "add")
    {
        person person_to_add;

        cout << "Input name, surname, date and money:\n";

        cin >> person_to_add.name;
        cin >> person_to_add.surname;
        cin >> person_to_add.date;
        cin >> person_to_add.sum;

        ofstream file_to_add("People.txt", ios::app);

        file_to_add << person_to_add.name << " " 
                    << person_to_add.surname << " " 
                    << person_to_add.date << " " 
                    << person_to_add.sum << endl;
        
        file_to_add.close();
    }


    system("pause");
}