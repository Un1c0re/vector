#include <iostream>
#include <cmath>
#include <sstream>
#include "vector.h"


double Vector::operator[](int i) const {
    int count = GetSize();
    if (count)
        if (i >= 0 && i < GetSize())
            return GetLength(i);
        else
            throw std::out_of_range("Index of List is out of range!");
    else
        throw std::length_error("List has no items.");
}


Vector& VList::operator[] (int i) {
    int count = Count();
    if (count)
        if (i >= 0 && i < count)
            return *(Vector *)GetItem(i);
        else
            throw std::out_of_range("Index of List is out of range!");
    else
        throw std::length_error("List has no items.");
}

Vector& Vector::operator = (Vector const& v) {
    delete length;

    length = new double(v.GetSize());
    size = v.GetSize();
    for(int i = 0; i < v.GetSize(); i++)
        length[i] = v[i];

    return *this;
}


/////////////////////////////////////////////////////////////////////////////


std::string Vector::ToString() {
    Vector& vector = *this;

    std::ostringstream res;
    res << "{ ";

    for(int i = 0; i < GetSize()-1; i++)
        res << vector[i] << ", ";
    res << vector[GetSize()-1] << " }";

    return res.str();
}


/////////////////////////////////////////////////////////////////////////////


void Vector::Input() {
    double value;
    for(int i = 0; i < GetSize(); i++) {
        while (printf("Input %d length: ", i+1),
                fflush(stdin), std::cin.clear(), !((std::cin >> value).good()))
            printf("ERROR: incorrect input. Try again\n");
        SetLength(value, i);
    }
}


void Vector::Print() {
    Vector& vector = *this;
    printf("{ ");
    for(int i = 0; i < GetSize()-1; i ++)
        printf("%lg, ", vector[i]);

    printf("%lg }\n", vector[GetSize()-1]);
}


double Vector::Module() {
    Vector& vector = *this;
    double module = 0;

    for(int i = 0; i < 3; i++)
        module += std::abs(pow(vector[i], 2));

    return sqrt(module);
}


double Vector::Angle(int a, int b) {

    if(GetSize() !=3)
        return false;

    Vector& vector = *this;


    double hypotenuse = pow(Module(), 2);
    double cathetus = pow(vector[a-1], 2) + pow(vector[b-1], 2);

    return acos(cathetus/hypotenuse)*180/M_PI;
}


void Vector::MultiplyByNumber(double num) {
    Vector& vector = *this;
    for(int i = 0; i < GetSize(); i++)
        SetLength(vector[i]*num, i);
}


void Vector::DivisionByNumber(int num) {
    Vector& vector = *this;
    for(int i = 0; i < GetSize(); i++)
        SetLength(vector[i]/num, i);
}


/////////////////////////////////////////////////////////////////////////////


void VList::PrintList() {
    VList& list = *this;

    for(int i = 0; i < Count(); i++) {
        printf("vector %d: ", i+1);
        list[i].Print();
        std::cout << std::endl;
    }
}


/////////////////////////////////////////////////////////////////////////////


bool VList::Compare(int a, int b) {

    if(!GetItem(a-1) || !GetItem(b-1))
        return false;

    VList& list = *this;

    Vector *x = &list[a-1];
    Vector *y = &list[b-1];

    if(list[a-1].GetSize() != list[b-1].GetSize())
        return false;

    for(int i = 0; i < x->GetSize(); i++)
        if((*x)[i] != (*y)[i])
            return false;
    return true;
}


double VList::ScalarMultiply(int a, int b) {
    VList& list = *this;

    if(!GetItem(a-1) || !GetItem(b-1))
        return -1;

    Vector *x =  &list[a-1];
    Vector *y =  &list[b-1];

    if(list[a-1].GetSize() != list[b-1].GetSize())
        return -1;

    double result = 0;

    for(int i = 0; i < x->GetSize(); i++)
        result += (*x)[i] * (*y)[i];
    return result;
}


double VList::VectorMultiply(int a, int b) {
    VList& list = *this;

    if(!GetItem(a-1) || !GetItem(b-1))
        return -1;

    Vector *x =  &list[a-1];
    Vector *y =  &list[b-1];

    if(list[a-1].GetSize() != list[b-1].GetSize() || list[a-1].GetSize() > 3)
        return -1;

    double result = 0;

    result = ((*x)[1] * (*y)[2] - (*x)[2] * (*y)[1])
           - ((*x)[0] * (*y)[2] - (*x)[2] * (*y)[0])
           + ((*x)[0] * (*y)[1] - (*x)[1] * (*y)[0]);

    return result;
}


Vector *VList::Summary(int a, int b) {
    if(!GetItem(a-1) || !GetItem(b-1)) {
        return nullptr;
    }

    VList& list = *this;

    Vector *x = &list[a-1];
    Vector *y = &list[b-1];

    if(list[a-1].GetSize() != list[b-1].GetSize())
        return nullptr;

    Vector *result = new Vector(x->GetSize());

    for(int i = 0; i < x->GetSize(); i++)
        result->SetLength((*x)[i] + (*y)[i], i);
    return result;
}


Vector *VList::Subtracting(int a, int b) {
    if(!GetItem(a-1) || !GetItem(b-1)) {
        return nullptr;
    }

    VList& list = *this;

    Vector *x = &list[a-1];
    Vector *y = &list[b-1];

    if(x->GetSize() != y->GetSize())
        return nullptr;

    Vector *result = new Vector(x->GetSize());

    for(int i = 0; i < x->GetSize(); i++)
        result->SetLength((*x)[i] - (*y)[i], i);

    return result;
}


bool VList::Collinearity(int a, int b) {
    if(!GetItem(a-1) || !GetItem(b-1)) {
        return false;
    }

    VList& list = *this;

    Vector *x = &list[a-1];
    Vector *y = &list[b-1];

    if(x->GetSize() != y->GetSize())
        return false;

    for(int i = 1; i < x->GetSize(); i++)
        if((*x)[0] / (*y)[0] != (*x)[i] / (*y)[i])
            return false;

    return true;
}


bool VList::Orthogonality(int a, int b) {
    if(!GetItem(a-1) || !GetItem(b-1)) {
        return false;
    }

    VList& list = *this;

    if(list[a-1].GetSize() != list[b-1].GetSize())
        return false;

    if(ScalarMultiply(a, b) != 0)
        return false;
    else
        return true;
}


bool VList::VectorAffiliation(int a, int b) {
    if(!GetItem(a-1) || !GetItem(b-1))
        return false;

    VList& list = *this;

    Vector *x = &list[a-1];
    Vector *y = &list[b-1];

    if(x->GetSize() != y->GetSize())
        return false;

    for(int i = 0; i < x->GetSize(); i ++)
        if(fmod((*y)[i], (*x)[i]) == 0 )
            return true;

    return false;
}


bool VList::PlaneAffiliation(int index, double a, double b, double c) {
    if(!GetItem(index-1))
        return false;

    VList& list = *this;
    if(list[index-1].GetSize() !=3)
        return false;

    Vector n(3);
    n.SetLength(a, 0);
    n.SetLength(b, 1);
    n.SetLength(c, 2);

    Vector *x =  &list[index];

    double result = 0;

    for(int i = 0; i < 3; i++)
        result += (*x)[i] * n[i];

    if( result == 0)
        return true;

    return false;
}
