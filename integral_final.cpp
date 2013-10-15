#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <cstring>
#include <queue>
#include <sstream>

using namespace std;

void integrando(string s)
{
    string delim1 = "*";
    string delim2 = "^";
    string delim3 = "x";

    int coef;
    int grado;

    size_t pos1 = 0;
    size_t pos2 = 0;
    size_t pos3 = 0;

    string parte;

    pos1 = s.find(delim1);
    pos2 = s.find(delim2);
    pos3 = s.find(delim3);

    int largos = s.length();

    if(pos1 == -1)
        coef = 1;
    else
    {
        coef = atoi((s.substr(0, pos1)).c_str());
    }

    if(pos2 == -1)
        grado = 1;
    else
    {
        grado = atoi((s.substr(pos2+1, largos)).c_str());
    }

    if(pos3 == -1)
        grado = 0;

    cout<<1.0*coef/(grado+1)<<"x^"<<grado+1;
}

int main(int argc, char * argv[])
{
    queue<string> cola;
    int i = 0;
    stringstream ss;
    string Polin;
    string mas("+");
    string menos("-");

    cout << "Ejecutable:" << argv[0] << "\n";

    for (i = 0; i < argc; i++)
        cout << "Argumento["<< i<<"]: " << argv[i] << "\n";

    string A = argv[2];
    int largo = A.length();

    for(int x=0; x < largo; x++)
    {
        if(A[x] == '-')
        {
            cola.push(menos);
        }
        else
        {
            if(A[x] == '+')
            {
                cola.push(mas);
            }
            else
            {
                while(A[x] != '-' && A[x] != '+' && x < largo)
                {
                    ss << A[x];
                    x++;
                }
                Polin = ss.str();
                ss.str("");
                cola.push(Polin);

                if(x < largo)
                    x--;
            }
        }
    }

    while (!cola.empty())
    {
        string PartePol = cola.front();
        cola.pop();

        if(PartePol == mas)
            cout << " + ";

        if(PartePol == menos)
            cout << " - ";

        if(PartePol != mas && PartePol != menos)
            integrando(PartePol);
    }
}

