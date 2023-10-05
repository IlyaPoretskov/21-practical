#include <iostream>
#include <cmath>
#include <string>

using namespace std;

struct vector
{
    double x, y;
};


bool input_control_digit(string n)
{

    int c = 0;

    if (n[0] == '-')
    {
        c++;
    }

    while (n[c] != '\0')
    {
        if (  !((n[c] >= '0' && n[c] <= '9') || n[c] == '.')  )
        {
            return false;
        }
        c++;
    }
    return true;
}


vector vec_add(vector& a, vector& b)
{
    return {a.x + b.x, a.y + b.y};
}

vector vec_substract(vector& a, vector& b)
{
    return {a.x - b.x, a.y - b.y};
}

vector vec_scale(vector& vec, double n)
{
    return {vec.x * n, vec.y * n};
}

double vec_length(vector& n)
{
    return sqrt(n.x * n.x + n.y * n.y); 
}

vector vec_normalize(vector& vec)
{
    return {vec.x / vec_length(vec), vec.y / vec_length(vec)};
}


int main()
{
    string command;

    cout << "Input command: ";
    cin >> command;

    while (command !=       "add" &&
           command != "substract" &&
           command !=     "scale" &&
           command !=    "length" &&
           command !=    "normalize")

    {
        cerr << "!Incorrect input!\n\n";
        cout << "Input command: ";
        cin >> command;
    }


    string x, y;

    cout << "Input vector x, y: ";

    cin >> x >> y;

    while (!input_control_digit(x) || !input_control_digit(y))
    {
        cout << "!Incorrect input!, input again: ";
        cin >> x >> y;
    }

    vector vec;

    vec.x = stof(x);
    vec.y = stof(y);



    if (command == "add") {

        string x2,  y2;

        cout << "Input second vector x, y: ";

        cin >> x2 >> y2;

        while (!input_control_digit(x2) || !input_control_digit(y2))
        {
            cout << "!Incorrect input!, input again: ";
            cin >> x2 >> y2;
        }

        vector vec2;

        vec2.x = stof(x2);
        vec2.y = stof(y2);

        cout << "Result: " << vec_add(vec, vec2).x << " " << vec_add(vec, vec2).y  << endl;
    }

    else if (command == "substract") {
        
        string x2, y2;

        cout << "Input vector x, y: ";

        cin >> x2 >> y2;

        while (!input_control_digit(x2) || !input_control_digit(y2))
        {
            cout << "!Incorrect input!, input again: ";
            cin >> x2 >> y2;
        }

        vector vec2;

        vec2.x = stof(x2);
        vec2.y = stof(y2);


        cout << "Result: " << vec_substract(vec, vec2).x << " " << vec_substract(vec, vec2).y  << endl;
        
    }

    else if (command == "scale") {

        string scalar_ch;

        cout << "Input scalar: ";
        cin >> scalar_ch;

        while (!input_control_digit(scalar_ch))
        {
            cout << "!Incorrect input!, input again: ";
            cin >> scalar_ch;
        }

        double scalar = stof(scalar_ch);
        
        cout << "Result: " << vec_scale(vec, scalar).x << " " << vec_scale(vec, scalar).y << endl;
        
    }

    else if (command == "length") {
        cout << "Length: " << vec_length(vec) << endl;
    }

    else if (command == "normalize") {
        cout << "Result: " << vec_normalize(vec).x << " " << vec_normalize(vec).y << endl;
    }

    system("pause");
    
}
