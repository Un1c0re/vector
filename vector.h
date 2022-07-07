#include "list.h"


class Vector : public Item {
private:
    int size;
    double *length;

public:
    explicit Vector(int len) : Item() { size = len; length = new double[len]; }

    double GetLength(int index) const {return length[index]; }
    int GetSize() const { return size; }
    void SetLength(double value, int index) { length[index] = value; }

    void Input();
    void Print();
    double Module();
    double Angle(int a, int b);
    void MultiplyByNumber(double num);
    void DivisionByNumber(int num);

    double operator[] (int i) const;
    std::string ToString();

    Vector& operator= (Vector const& v);
};


class VList : public List {
public:
    VList() : List() {}

    void PrintList();

    double ScalarMultiply(int a, int b);
    double VectorMultiply(int a, int b);
    Vector *Summary(int a, int b);
    Vector *Subtracting(int a, int b);
    bool Compare(int a, int b);
    bool Collinearity(int a, int b);
    bool Orthogonality(int a, int b);
    bool VectorAffiliation(int a, int b);
    bool PlaneAffiliation(int index, double a, double b, double c);

    Vector& operator[] (int i);
};
