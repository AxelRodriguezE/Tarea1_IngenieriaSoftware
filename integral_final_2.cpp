#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <cstring>
#include <queue>
#include <sstream>
#include "ExpressionParser.h"

using namespace std;

stringstream resultado;

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

    resultado << "(";
    resultado << 1.0*coef/(grado+1);
    resultado << ")*(x^";
    resultado << grado+1;
    resultado << ")";
}

int main(int argc, char * argv[])
{
    queue<string> cola;
    int i = 0;
    stringstream ss;
    string Polin;
    string mas("+");
    string menos("-");

    string indicador = argv[1];

    if(indicador == "-v")
    {
        cout << "Trabajo realizado por: " << endl;
        cout << "                       Axel Rodriguez Espinoza. Estudiante de Ingenieria en informatica UTEM" << endl;
        cout << "                       Nicolas Oyarzun Hernandez. Estudiante de Ingenieria civil en computacion mencion informatica UTEM" << endl;
        cout << "                       Pedro Salas Vergara. Estudiante de Ingenieria civil en computacion mencion informatica UTEM" << endl;
        cout << "Compilado el " << __DATE__ << ", a las " << __TIME__ << endl;
        exit(0);
    }

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
        {
            resultado << "+";
        }

        if(PartePol == menos)
        {
            resultado << "-";
        }

        if(PartePol != mas && PartePol != menos)
            integrando(PartePol);
    }
    cout << resultado.str() << endl;


    if(indicador == "-g")
    {
        string ecuacion1;
        ecuacion1 = resultado.str();
        cout << ecuacion1 << endl;

        string ecuacion2;
        ecuacion2 = resultado.str();
        cout << ecuacion2 << endl;

        char reemplaza1 = 'x';
        char reemplaza2 = '^';

        string inf = argv[3];
        string sup = argv[4];
        string potencia("**");

        int j;

        for(j=0; j<ecuacion1.length(); j++)
        {
            if(ecuacion1[j] == reemplaza1)
                ecuacion1.replace(j, 1, inf);
            if(ecuacion1[j] == reemplaza2)
                ecuacion1.replace(j, 1, potencia);
        }


        for(j=0; j<ecuacion2.length(); j++)
        {
            if(ecuacion2[j] == reemplaza1)
                ecuacion2.replace(j, 1, sup);
            if(ecuacion2[j] == reemplaza2)
                ecuacion2.replace(j, 1, potencia);
        }
        string ecuacion("2*(3,0)+(6**2)");

        ExpressionParser<int> parser1;
        ExpressionParser<int> parser2;
        ExpressionParser<int> parser;

        //cout << ecuacion1 << ", " << ecuacion2 << endl;

        //int hasta = parser2.eval(ecuacion2);
        //int desde = parser1.eval(ecuacion1);

        cout << parser.eval(ecuacion) << endl;
        //cout << ecuacion1 << " - " << ecuacion2 << " = " << (hasta - desde) << endl;
        //cout << resultado.str() << " = " << parser.eval(resultado.str()) << endl;
    }
}

