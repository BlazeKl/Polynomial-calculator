#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

typedef struct node
{
    int coeff;
    int exp;
    node *link;
};

typedef node *list_p;

class polynomial
{
    public:
        /** Default constructor */
        polynomial();
        /** Default destructor */
        ~polynomial();
        void add_mono(int,int);
        void add_mono_l(int,int);
        void clean_pol();
        void show_pol();
        void getcopy(polynomial &);
        void change_sign();
        void der();
        void add_p(polynomial,polynomial);
        void mult_p(polynomial,polynomial);
        void div_p(polynomial,polynomial);
        void ultimatefix();
    protected:
    private:
        list_p L;
};

#endif // POLYNOMIAL_H
