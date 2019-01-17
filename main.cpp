#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include "polynomial.h"


using namespace std;

int main()
{
    cout << "Polynomial calculator using list class by Felipe Perez" << endl;
    cout << "*-------------------------------------------* " << endl;
    cout << "|This program requires a file named         | " << endl;
    cout << "|'data.txt' if the file doesn't exist       | " << endl;
    cout << "|the program won't work. The file contains  | " << endl;
    cout << "|a template of how to format the operations,| " << endl;
    cout << "|it can be modified as needed               | " << endl;
    cout << "|Numbers must be at 0<=n<100                | " << endl;
    cout << "*-------------------------------------------* " << endl;
    cout << "" << endl;
    polynomial p1;//Polinomios para declarar
    polynomial p2;
    polynomial p3;
    polynomial p4;
    polynomial p5;
    polynomial r;
    polynomial aux1;
    polynomial aux2;
    string snum1 = ""; //numeros a obtener en string
    string snum2 = "";
    int state=0;
    string line; //guardar cada linea de texto aqui
    string line_aux; // si voy a modificar la linea guarda lo original aca
    int sizestr;
    ifstream file("data.txt");
    if(!file)
    {
        cout << "No se encontro el archivo!" << endl;
        cout << "Presione 'Enter' para terminar . . . " << endl;
        getchar();
    }
    else
    {
        while(getline(file,line))
        {
            if(line=="Polinomios:")
            {
                cout << "Declaracion de polinomios: " << endl;
                while(getline(file,line) && line!="")
                {
                    if(line[1]=='1')
                    {
                        for(int i=3; i < line.size() ; i++)
                        {

                            if(line[i]=='#')
                                {}
                            else
                            {
                                if(line[i]=='-')
                                {
                                    if(state==0) // neñ estado 0 no ha encontrado ningun numero
                                        snum1 += "-"; // encontro la base, le agrega el - a un struing
                                    if(state==1) // el xponente queda negativo
                                        snum2 += "-";
                                    i++; // avanza al sgt caracter
                                }
                                if(line[i]=='0' || line[i]=='1' || line[i]=='2' || line[i]=='3' || line[i]=='4' || line[i]=='5' || line[i]=='6' || line[i]=='7' || line[i]=='8' || line[i]=='9')
                                {
                                    if(line[i+1]=='0' || line[i+1]=='1' || line[i+1]=='2' || line[i+1]=='3' || line[i+1]=='4' || line[i+1]=='5' || line[i+1]=='6' || line[i+1]=='7' || line[i+1]=='8' || line[i+1]=='9')
                                    {// verifica si hay un numero, es por si es un numero de 2 digitos, no se podra poner 3 digitos, 0-99
                                        if(state==0)// agreaga al string , al primer digito y agreaga al segundo
                                        {
                                            snum1 += line[i]; //primer digito
                                            i++;
                                            snum1 += line[i];// segundo digito agregado al string
                                            //state++;
                                        }
                                        if(state==1) // es por si el exponente  o-99
                                        {
                                            snum2 += line[i];
                                            i++;
                                            snum2 += line[i];
                                            //state++;
                                        }
                                        state++; // se avanza al sgt
                                    }
                                    else// caso en que sea solo un digito el numero
                                    {
                                        if(state==0)
                                        {
                                            snum1 += line[i]; // agreaga el UNICO digito al string
                                            //state++;
                                        }
                                        if(state==1)
                                        {
                                            snum2 += line[i]; // agreaga el UNICO exponente al string
                                            //state++;
                                        }
                                        state++;
                                    }
                                }
                                if(state==2) // el estado ya tiene un un expoenten y base, por ejemplo en p1 seria snum 1= "2" y sunm2=="3"
                                {
                                    p1.add_mono(atoi(snum1.c_str()),atoi(snum2.c_str()));// atoi recibe como parametro el string y lo transforma a un entero
                                    snum1 = "";//deja el snum1 como vacio, para si luego volver al ciclo
                                    snum2 = "";//
                                    state=0;
                                }
                            }
                        }
                        cout << "p1 = ";// imrpime p1
                        p1.show_pol();
                        cout << endl;
                    }
                    if(line[1]=='2')
                    {
                        for(int i=3; i < line.size() ; i++)
                        {
                            if(line[i]=='#')
                                {}
                            else
                            {
                                if(line[i]=='-')
                                {
                                    if(state==0)
                                        snum1 += "-";
                                    if(state==1)
                                        snum2 += "-";
                                    i++;
                                }
                                if(line[i]=='0' || line[i]=='1' || line[i]=='2' || line[i]=='3' || line[i]=='4' || line[i]=='5' || line[i]=='6' || line[i]=='7' || line[i]=='8' || line[i]=='9')
                                {
                                    if(line[i+1]=='0' || line[i+1]=='1' || line[i+1]=='2' || line[i+1]=='3' || line[i+1]=='4' || line[i+1]=='5' || line[i+1]=='6' || line[i+1]=='7' || line[i+1]=='8' || line[i+1]=='9')
                                    {
                                        if(state==0)
                                        {
                                            snum1 += line[i];
                                            i++;
                                            snum1 += line[i];
                                            //state++;
                                        }
                                        if(state==1)
                                        {
                                            snum2 += line[i];
                                            i++;
                                            snum2 += line[i];
                                            //state++;
                                        }
                                        state++;
                                    }
                                    else
                                    {
                                        if(state==0)
                                        {
                                            snum1 += line[i];
                                            //state++;
                                        }
                                        if(state==1)
                                        {
                                            snum2 += line[i];
                                            //state++;
                                        }
                                        state++;
                                    }
                                }
                                if(state==2)
                                {
                                    p2.add_mono(atoi(snum1.c_str()),atoi(snum2.c_str()));
                                    snum1 = "";
                                    snum2 = "";
                                    state=0;
                                }
                            }
                        }
                        cout << "p2 = ";
                        p2.show_pol();
                        cout << endl;
                    }
                    if(line[1]=='3')
                    {
                        for(int i=3; i < line.size() ; i++)
                        {
                            if(line[i]=='#')
                                {}
                            else
                            {
                                if(line[i]=='-')
                                {
                                    if(state==0)
                                        snum1 += "-";
                                    if(state==1)
                                        snum2 += "-";
                                    i++;
                                }
                                if(line[i]=='0' || line[i]=='1' || line[i]=='2' || line[i]=='3' || line[i]=='4' || line[i]=='5' || line[i]=='6' || line[i]=='7' || line[i]=='8' || line[i]=='9')
                                {
                                    if(line[i+1]=='0' || line[i+1]=='1' || line[i+1]=='2' || line[i+1]=='3' || line[i+1]=='4' || line[i+1]=='5' || line[i+1]=='6' || line[i+1]=='7' || line[i+1]=='8' || line[i+1]=='9')
                                    {
                                        if(state==0)
                                        {
                                            snum1 += line[i];
                                            i++;
                                            snum1 += line[i];
                                            //state++;
                                        }
                                        if(state==1)
                                        {
                                            snum2 += line[i];
                                            i++;
                                            snum2 += line[i];
                                            //state++;
                                        }
                                        state++;
                                    }
                                    else
                                    {
                                        if(state==0)
                                        {
                                            snum1 += line[i];
                                            //state++;
                                        }
                                        if(state==1)
                                        {
                                            snum2 += line[i];
                                            //state++;
                                        }
                                        state++;
                                    }
                                }
                                if(state==2)
                                {
                                    p3.add_mono(atoi(snum1.c_str()),atoi(snum2.c_str()));
                                    snum1 = "";
                                    snum2 = "";
                                    state=0;
                                }
                            }
                        }
                        cout << "p3 = ";
                        p3.show_pol();
                        cout << endl;
                    }
                    if(line[1]=='4')
                    {
                        for(int i=3; i < line.size() ; i++)
                        {
                            if(line[i]=='#')
                                {}
                            else
                            {
                                if(line[i]=='-')
                                {
                                    if(state==0)
                                        snum1 += "-";
                                    if(state==1)
                                        snum2 += "-";
                                    i++;
                                }
                                if(line[i]=='0' || line[i]=='1' || line[i]=='2' || line[i]=='3' || line[i]=='4' || line[i]=='5' || line[i]=='6' || line[i]=='7' || line[i]=='8' || line[i]=='9')
                                {
                                    if(line[i+1]=='0' || line[i+1]=='1' || line[i+1]=='2' || line[i+1]=='3' || line[i+1]=='4' || line[i+1]=='5' || line[i+1]=='6' || line[i+1]=='7' || line[i+1]=='8' || line[i+1]=='9')
                                    {
                                        if(state==0)
                                        {
                                            snum1 += line[i];
                                            i++;
                                            snum1 += line[i];
                                            //state++;
                                        }
                                        if(state==1)
                                        {
                                            snum2 += line[i];
                                            i++;
                                            snum2 += line[i];
                                            //state++;
                                        }
                                        state++;
                                    }
                                    else
                                    {
                                        if(state==0)
                                        {
                                            snum1 += line[i];
                                            //state++;
                                        }
                                        if(state==1)
                                        {
                                            snum2 += line[i];
                                            //state++;
                                        }
                                        state++;
                                    }
                                }
                                if(state==2)
                                {
                                    p4.add_mono(atoi(snum1.c_str()),atoi(snum2.c_str()));
                                    snum1 = "";
                                    snum2 = "";
                                    state=0;
                                }
                            }
                        }
                        cout << "p4 = ";
                        p4.show_pol();
                        cout << endl;
                    }
                    if(line[1]=='5')
                    {
                        for(int i=3; i < line.size() ; i++)
                        {
                            if(line[i]=='#')
                                {}
                            else
                            {
                                if(line[i]=='-')
                                {
                                    if(state==0)
                                        snum1 += "-";
                                    if(state==1)
                                        snum2 += "-";
                                    i++;
                                }
                                if(line[i]=='0' || line[i]=='1' || line[i]=='2' || line[i]=='3' || line[i]=='4' || line[i]=='5' || line[i]=='6' || line[i]=='7' || line[i]=='8' || line[i]=='9')
                                {
                                    if(line[i+1]=='0' || line[i+1]=='1' || line[i+1]=='2' || line[i+1]=='3' || line[i+1]=='4' || line[i+1]=='5' || line[i+1]=='6' || line[i+1]=='7' || line[i+1]=='8' || line[i+1]=='9')
                                    {
                                        if(state==0)
                                        {
                                            snum1 += line[i];
                                            i++;
                                            snum1 += line[i];
                                            //state++;
                                        }
                                        if(state==1)
                                        {
                                            snum2 += line[i];
                                            i++;
                                            snum2 += line[i];
                                            //state++;
                                        }
                                        state++;
                                    }
                                    else
                                    {
                                        if(state==0)
                                        {
                                            snum1 += line[i];
                                            //state++;
                                        }
                                        if(state==1)
                                        {
                                            snum2 += line[i];
                                            //state++;
                                        }
                                        state++;
                                    }
                                }
                                if(state==2)
                                {
                                    p5.add_mono(atoi(snum1.c_str()),atoi(snum2.c_str()));
                                    snum1 = "";
                                    snum2 = "";
                                    state=0;
                                }
                            }
                        }
                        cout << "p5 = ";
                        p5.show_pol();
                        cout << endl;
                    }
                }
            }
            if(line=="Expresiones:")// verifica  que sean expresiones las expresiones
            {
                cout << endl;
                cout << "Operaciones : " << endl;
                while(getline(file,line) && line!="")
                {
                    line_aux=line;// se guarda  la linea porq se modificara
                    sizestr = line.size();// se guarda el tamaño en un entero, este numero, se ira modificando
                    for(int i=0;i<sizestr;i++)
                    {
                        if(line[i]=='(')//verificasi hay un parentesis
                        {
                            int j=i;
                            while(line[j]!=')')// parara cuando se cierrre el signo
                            {
                                if(line[j]=='*')// cuando sea igual a mult.
                                {
                                    if(line[j-1]=='1')
                                    {
                                        p1.getcopy(aux1);
                                    }
                                    if(line[j-1]=='2')
                                    {
                                        p2.getcopy(aux1);
                                    }
                                    if(line[j-1]=='3')
                                    {
                                        p3.getcopy(aux1);
                                    }
                                    if(line[j-1]=='4')
                                    {
                                        p4.getcopy(aux1);
                                    }
                                    if(line[j-1]=='5')
                                    {
                                        p5.getcopy(aux1);
                                    }
                                    if(line[j+2]=='1')
                                    {
                                        p1.getcopy(aux2);
                                    }
                                    if(line[j+2]=='2')
                                    {
                                        p2.getcopy(aux2);
                                    }
                                    if(line[j+2]=='3')
                                    {
                                        p3.getcopy(aux2);
                                    }
                                    if(line[j+2]=='4')
                                    {
                                        p4.getcopy(aux2);
                                    }
                                    if(line[j+2]=='5')
                                    {
                                        p5.getcopy(aux2);
                                    }
                                    r.mult_p(aux1,aux2);
                                }
                                if(line[j]=='/')
                                {
                                    if(line[j-1]=='1')
                                    {
                                        p1.getcopy(aux1);
                                    }
                                    if(line[j-1]=='2')
                                    {
                                        p2.getcopy(aux1);
                                    }
                                    if(line[j-1]=='3')
                                    {
                                        p3.getcopy(aux1);
                                    }
                                    if(line[j-1]=='4')
                                    {
                                        p4.getcopy(aux1);
                                    }
                                    if(line[j-1]=='5')
                                    {
                                        p5.getcopy(aux1);
                                    }
                                    if(line[j+2]=='1')
                                    {
                                        p1.getcopy(aux2);
                                    }
                                    if(line[j+2]=='2')
                                    {
                                        p2.getcopy(aux2);
                                    }
                                    if(line[j+2]=='3')
                                    {
                                        p3.getcopy(aux2);
                                    }
                                    if(line[j+2]=='4')
                                    {
                                        p4.getcopy(aux2);
                                    }
                                    if(line[j+2]=='5')
                                    {
                                        p5.getcopy(aux2);
                                    }
                                    r.div_p(aux1,aux2);
                                }
                                if(line[j]=='+')
                                {
                                    if(line[j-1]=='1')
                                    {
                                        p1.getcopy(aux1);
                                    }
                                    if(line[j-1]=='2')
                                    {
                                        p2.getcopy(aux1);
                                    }
                                    if(line[j-1]=='3')
                                    {
                                        p3.getcopy(aux1);
                                    }
                                    if(line[j-1]=='4')
                                    {
                                        p4.getcopy(aux1);
                                    }
                                    if(line[j-1]=='5')
                                    {
                                        p5.getcopy(aux1);
                                    }
                                    if(line[j+2]=='1')
                                    {
                                        p1.getcopy(aux2);
                                    }
                                    if(line[j+2]=='2')
                                    {
                                        p2.getcopy(aux2);
                                    }
                                    if(line[j+2]=='3')
                                    {
                                        p3.getcopy(aux2);
                                    }
                                    if(line[j+2]=='4')
                                    {
                                        p4.getcopy(aux2);
                                    }
                                    if(line[j+2]=='5')
                                    {
                                        p5.getcopy(aux2);
                                    }
                                    r.add_p(aux1,aux2);
                                }
                                if(line[j]=='-')
                                {
                                    if(line[j-1]=='1')
                                    {
                                        p1.getcopy(aux1);
                                    }
                                    if(line[j-1]=='2')
                                    {
                                        p2.getcopy(aux1);
                                    }
                                    if(line[j-1]=='3')
                                    {
                                        p3.getcopy(aux1);
                                    }
                                    if(line[j-1]=='4')
                                    {
                                        p4.getcopy(aux1);
                                    }
                                    if(line[j-1]=='5')
                                    {
                                        p5.getcopy(aux1);
                                    }
                                    if(line[j+2]=='1')
                                    {
                                        p1.getcopy(aux2);
                                    }
                                    if(line[j+2]=='2')
                                    {
                                        p2.getcopy(aux2);
                                    }
                                    if(line[j+2]=='3')
                                    {
                                        p3.getcopy(aux2);
                                    }
                                    if(line[j+2]=='4')
                                    {
                                        p4.getcopy(aux2);
                                    }
                                    if(line[j+2]=='5')
                                    {
                                        p5.getcopy(aux2);
                                    }
                                    aux2.change_sign();
                                    r.add_p(aux1,aux2);
                                    aux2.change_sign();
                                }
                                if(line[j-3]=='d' && line[j-2]=='e' && line[j-1]=='r')
                                {
                                    if(line[j+2]=='1')
                                    {
                                        p1.getcopy(r);
                                    }
                                    if(line[j+2]=='2')
                                    {
                                        p2.getcopy(r);
                                    }
                                    if(line[j+2]=='3')
                                    {
                                        p3.getcopy(r);
                                    }
                                    if(line[j+2]=='4')
                                    {
                                        p4.getcopy(r);
                                    }
                                    if(line[j+2]=='5')
                                    {
                                        p5.getcopy(r);
                                    }
                                    r.der();
                                }
                                j++;
                            }
                            line[i]='r';
                            line[i+1]='r';
                            line.erase(i+2,j-1);
                            sizestr = line.size();
                        }
                    }
                    for(int i=0;i<sizestr;i++)
                    {
                        if(line[i]=='*')
                        {
                            if(line[i-1]=='r')
                            {
                                r.getcopy(aux1);
                            }
                            if(line[i-1]=='1')
                            {
                                p1.getcopy(aux1);
                            }
                            if(line[i-1]=='2')
                            {
                                p2.getcopy(aux1);
                            }
                            if(line[i-1]=='3')
                            {
                                p3.getcopy(aux1);
                            }
                            if(line[i-1]=='4')
                            {
                                p4.getcopy(aux1);
                            }
                            if(line[i-1]=='5')
                            {
                                p5.getcopy(aux1);
                            }
                            if(line[i+2]=='1')
                            {
                                p1.getcopy(aux2);
                            }
                            if(line[i+2]=='2')
                            {
                                p2.getcopy(aux2);
                            }
                            if(line[i+2]=='3')
                            {
                                p3.getcopy(aux2);
                            }
                            if(line[i+2]=='4')
                            {
                                p4.getcopy(aux2);
                            }
                            if(line[i+2]=='5')
                            {
                                p5.getcopy(aux2);
                            }
                            if(line[i+2]=='r')
                            {
                                r.getcopy(aux2);
                            }
                            r.mult_p(aux1,aux2);
                            line[i-2]='r';
                            line[i-1]='r';
                            line.erase(i,i+1);
                            sizestr = line.size();
                            i=0;
                        }
                        if(line[i]=='/')
                        {
                            if(line[i-1]=='r')
                            {
                                r.getcopy(aux1);
                            }
                            if(line[i-1]=='1')
                            {
                                p1.getcopy(aux1);
                            }
                            if(line[i-1]=='2')
                            {
                                p2.getcopy(aux1);
                            }
                            if(line[i-1]=='3')
                            {
                                p3.getcopy(aux1);
                            }
                            if(line[i-1]=='4')
                            {
                                p4.getcopy(aux1);
                            }
                            if(line[i-1]=='5')
                            {
                                p5.getcopy(aux1);
                            }
                            if(line[i+2]=='1')
                            {
                                p1.getcopy(aux2);
                            }
                            if(line[i+2]=='2')
                            {
                                p2.getcopy(aux2);
                            }
                            if(line[i+2]=='3')
                            {
                                p3.getcopy(aux2);
                            }
                            if(line[i+2]=='4')
                            {
                                p4.getcopy(aux2);
                            }
                            if(line[i+2]=='5')
                            {
                                p5.getcopy(aux2);
                            }
                            if(line[i+2]=='r')
                            {
                                r.getcopy(aux2);
                            }
                            r.div_p(aux1,aux2);
                            line[i-2]='r';
                            line[i-1]='r';
                            line.erase(i,i+1);
                            sizestr = line.size();
                            i=0;
                        }
                    }
                    for(int i=0;i<sizestr;i++)
                    {
                        if(line[i]=='+')
                        {
                            if(line[i-1]=='r')
                            {
                                r.getcopy(aux1);
                            }
                            if(line[i-1]=='1')
                            {
                                p1.getcopy(aux1);
                            }
                            if(line[i-1]=='2')
                            {
                                p2.getcopy(aux1);
                            }
                            if(line[i-1]=='3')
                            {
                                p3.getcopy(aux1);
                            }
                            if(line[i-1]=='4')
                            {
                                p4.getcopy(aux1);
                            }
                            if(line[i-1]=='5')
                            {
                                p5.getcopy(aux1);
                            }
                            if(line[i+2]=='1')
                            {
                                p1.getcopy(aux2);
                            }
                            if(line[i+2]=='2')
                            {
                                p2.getcopy(aux2);
                            }
                            if(line[i+2]=='3')
                            {
                                p3.getcopy(aux2);
                            }
                            if(line[i+2]=='4')
                            {
                                p4.getcopy(aux2);
                            }
                            if(line[i+2]=='5')
                            {
                                p5.getcopy(aux2);
                            }
                            if(line[i+2]=='r')
                            {
                                r.getcopy(aux2);
                            }
                            r.add_p(aux1,aux2);
                            line[i-2]='r';
                            line[i-1]='r';
                            line.erase(i,i+1);
                            sizestr = line.size();
                            i=0;
                        }
                        if(line[i]=='-')
                        {
                            if(line[i-1]=='r')
                            {
                                r.getcopy(aux1);
                            }
                            if(line[i-1]=='1')
                            {
                                p1.getcopy(aux1);
                            }
                            if(line[i-1]=='2')
                            {
                                p2.getcopy(aux1);
                            }
                            if(line[i-1]=='3')
                            {
                                p3.getcopy(aux1);
                            }
                            if(line[i-1]=='4')
                            {
                                p4.getcopy(aux1);
                            }
                            if(line[i-1]=='5')
                            {
                                p5.getcopy(aux1);
                            }
                            if(line[i+2]=='1')
                            {
                                p1.getcopy(aux2);
                            }
                            if(line[i+2]=='2')
                            {
                                p2.getcopy(aux2);
                            }
                            if(line[i+2]=='3')
                            {
                                p3.getcopy(aux2);
                            }
                            if(line[i+2]=='4')
                            {
                                p4.getcopy(aux2);
                            }
                            if(line[i+2]=='5')
                            {
                                p5.getcopy(aux2);
                            }
                            if(line[i+2]=='r')
                            {
                                r.getcopy(aux2);
                            }
                            aux2.change_sign();
                            r.add_p(aux1,aux2);
                            aux2.change_sign();
                            line[i-2]='r';
                            line[i-1]='r';
                            line.erase(i,i+1);
                            sizestr = line.size();
                            i=0;
                        }
                    }
                    cout << line_aux << " = ";
                    r.ultimatefix();
                    r.show_pol();
                    cout << endl;
                    r.clean_pol();
                }
            }
        }

    }
    cout << "Presione 'Enter' para terminar . . . " << endl;
    getchar();
    return 0;
}
