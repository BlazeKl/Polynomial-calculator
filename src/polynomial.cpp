#include "polynomial.h"
#include <iostream>

using namespace std;

/*void add_right(list_p &L, int e1,int e2)
{
    list_p p,q;
    q = L;
    p = new(node);
    p->coeff = e1;
    p->exp = e2;
    p->link = NULL;

    if(q==NULL)
        L = p;
    else{
        while(q->link != NULL){
            q = q->link;
        }
        q->link = p;
    }
}

void show_list(list_p x) //for debug-only
{
    list_p y;
    y=x;
    while(y!=NULL)
    {
        cout << y->coeff << "x^" << y->exp;
        y=y->link;
    }
}*/

void delete_n(list_p &L, int x,int y)
{
    list_p p;
    if(L==NULL)//si no es null
    { }
    else{
        if(L->coeff!=x || L->exp!=y)//
            delete_n(L->link,x,y);
        else{
            p = L;
            L = L->link;
            delete(p);
        }
    }
}

polynomial::polynomial()
{
    L=NULL;
}

polynomial::~polynomial()
{

}

void polynomial::add_mono(int x, int y)
{
    list_p p,q;//punteros tipo lista aux
    q = L;//
    p = new(node);// un nuevo nodo
    p->coeff = x;//apunta al nodo de a base, y se iguala a x
    p->exp = y;// apunta al nodo de exp
    p->link = NULL;
    if(q==NULL)
        L = p; // se termina apuntando la lista L a P
    else
    {
        while(q->link != NULL)// si no es igual a null, hasta q q->link sea null
        {
            q = q->link;
        }
        q->link = p; //
    }
}

void polynomial::clean_pol()
{
    delete(L);//elimina la lista ypar luego que paunte a null, para satisfacer que x apunte a nada
    L=NULL;
}

void polynomial::getcopy(polynomial &x)// se guarda una copia en X de variable p1,p2,p3,p4,p5
{
    list_p p;// puntero aux
    p=L;
    x.clean_pol();// se asegura que este limpia
    while(p!=NULL)//
    {
        x.add_mono(p->coeff,p->exp);
        p=p->link;
    }
}

void polynomial::add_mono_l(int x,int y)
{
    list_p p;
    p = new(node);
    p->coeff=x;
    p->exp=y;
    p->link=L;
    L=p;
}



void polynomial::show_pol()
{
    list_p p;// se crea un puntero aux
    p=L;
    if(p==NULL)// si esta vacia imprime esto
        cout << "Polinomio vacio!";
    while(p!=NULL)//
    {
        if(p==L)// si el primer nodo
        {
            if(p->coeff!=0)// verifica que la base sea diferente de 0
                cout << p->coeff << "x^" << p->exp;// entonces imprime por pantalla
        }
        else
        {
            if(p->coeff!=0)// si la  base es distinto de 0 y no es el primer digito entonces se imprime(porq si o si en el archivo venra un sugno)
                cout << "+" << p->coeff << "x^" << p->exp;
        }
        p=p->link;
    }
}

void polynomial::change_sign()
{
    list_p p;
    p=L;
    while(p!=NULL)
    {
        p->coeff*=-1;
        p=p->link;
    }
}

void polynomial::der()
{
    list_p p;
    p=L;
    while(p!=NULL)
    {
        p->coeff=p->coeff*p->exp;
        p->exp+=-1;
        p=p->link;
    }
}

void polynomial::add_p(polynomial p1,polynomial p2)
{
    list_p p,q;
    int exp_g=0;
    int x,y;
    int stat=0;
    p=p1.L;
    while (p!=NULL)
    {
        q=p2.L;
        while (q!=NULL)
        {
            if(p->exp == q->exp)
            {
                x=p->coeff + q->coeff;
                y=p->exp;
                if(y>=exp_g)
                {
                    exp_g=y;
                    add_mono_l(x,y);
                }
                else
                    add_mono(x,y);
            }
            q=q->link;
        }
        p=p->link;
    }
    p=p1.L;
    q=L;
    if(q==NULL)
    {
        while(p!=NULL)
        {
            x=p->coeff;
            y=p->exp;
            add_mono_l(x,y);
        }
    }
    else
    {
        while(p!=NULL)
        {
            while(q!=NULL)
            {
                if(p->exp == q->exp)
                    stat=1;
                q=q->link;
            }
            q=L;
            if(stat==0)
            {
                x=p->coeff;
                y=p->exp;
                if(y>=exp_g)
                {
                    exp_g=y;
                    add_mono_l(x,y);
                }
                else
                    add_mono(x,y);
            }
            p=p->link;
            stat=0;
        }
    }
    p=p2.L;
    q=L;
    if(q==NULL)
    {
        while(p!=NULL)
        {
            x=p->coeff;
            y=p->exp;
            add_mono_l(x,y);
        }
    }
    else
    {
        while(p!=NULL)
        {
            while(q!=NULL)
            {
                if(p->exp == q->exp)
                    stat=1;
                q=q->link;
            }
            q=L;
            if(stat==0)
            {
                x=p->coeff;
                y=p->exp;
                if(y>=exp_g)
                {
                    exp_g=y;
                    add_mono_l(x,y);
                }
                else
                    add_mono(x,y);
            }
            p=p->link;
            stat=0;
        }
    }
}

void polynomial::mult_p(polynomial p1,polynomial p2)
{
    list_p p=NULL,q=NULL;// 2 punteros aux
    int x,y;// 2 enteros aux
    p=p1.L;//
    q=p2.L;//
    while(p!=NULL)// verifica que no este al final del polinomio
    {
        q=p2.L;
        while(q!=NULL)
        {
            x=p->coeff*q->coeff;// las bases se mult.
            y=p->exp+q->exp;// los exp se suman
            add_mono(x,y);//se agrega al avariable r
            q=q->link;//
        }
        p=p->link;
    }
    p=L;
    q=L;
    while(p!=NULL)
    {
        q=L;
        while(q!=NULL)
        {
            if(p == q)
            {}
            else if(p->exp == q->exp)// verifica si los exp son iguales
            {
                p->coeff += q->coeff;
                delete_n(L,q->coeff,q->exp);
                p=L;
                q=L;
            }
            q=q->link;
        }
        p=p->link;
    }
}

void polynomial::div_p(polynomial p1,polynomial p2)
{
    cout << "[WARN] Division not implemented" << endl;
}

void polynomial::ultimatefix()
{
    list_p p,q;
    p=L;
    q=L;
    while(p!=NULL)
    {
        q=L;
        while(q!=NULL)
        {
            if(p == q)
            {}
            else if(p->exp == q->exp)
            {
                p->coeff += q->coeff;
                delete_n(L,q->coeff,q->exp);
                p=L;
                q=L;
            }
            q=q->link;
        }
        p=p->link;
    }
    p=L;
    q=L;
    int x,y;
    while(p!=NULL)
    {
        q=L;
        while(q!=NULL)
        {
            if(q->exp < p->exp)
            {
                x= p->coeff;
                y= p->exp;
                p->coeff = q->coeff;
                p->exp = q->exp;
                q->coeff = x;
                q->exp = y;
            }
            q=q->link;
        }
        p=p->link;
    }
}
