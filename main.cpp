#include <iostream>

#include "vector.h"

using namespace std;

int main() {

    VList list;
    Vector *v;
    Vector *v1, *v2;
    int arg, a, b, c, index;
    double val6;
    std::string menu [19] = {
            "1. Print list",
            "2. Add vector",
            "3. Delete vector",
            "4. Module vector",
            "5. Angle between vector and plane",
            "6. Multiply vector by a number",
            "7. Division vector by a number",
            "8. Scalar multiply of vectors",
            "9. Vector multiply of vectors",
            "10. Summary of Vectors",
            "11. Subtract of vectors",
            "12. Vectors equal",
            "13. Collinearity of vectors",
            "14. Orthogonality of vectors",
            "15. Belonging one vector to another",
            "16. Belonging of the vector to the plane",
            "17. Replace vector",
            "18. Print in string format",
            "0. Exit"
    };

    int key;
    do {
        system("cls");
        for(auto & i : menu) {
            cout << i << endl;
        }
        fflush(stdin);
        cin >> key;

        switch(key) {
            case 1:  // Print list
                if(list.GetItem(0))
                    list.PrintList();
                else
                    cout << "List is empty!\n";

                system("pause");
                break;

            case 2:  // Add vector
                while (printf("Input vector norma: "),
                        fflush(stdin), cin.clear(), !((cin >> arg).good()))
                    printf("ERROR: incorrect input. Try again\n");

                v = new Vector(arg);

                v->Input();
                list.Add((Item *)v);

                system("pause");
                break;

            case 3:  // Delete vector
                while (printf("Which one vector to delete?: "),
                        fflush(stdin), cin.clear(), !((cin >> arg).good()) || arg > list.Count())
                    printf("ERROR: incorrect input. Try again\n");

                if(list.GetItem(0))
                    list.Delete(arg-1);
                break;

            case 4:  // Module vector
                while (printf("Choose vector: "),
                        fflush(stdin), cin.clear(), !((cin >> arg).good()) || arg > list.Count())
                    printf("ERROR: incorrect input. Try again\n");
                v = (Vector *)list.GetItem(arg-1);
                printf("Module of vector %d: %lg\n", arg, v->Module());

                system("pause");
                break;

            case 5:  // Angle between vector and plane
                while (printf("Choose vector: "),
                        fflush(stdin), cin.clear(), !((cin >> arg).good()) || arg > list.Count())
                    printf("ERROR: incorrect input. Try again\n");
                v = (Vector *)list.GetItem(arg-1);

                int d1, d2;
                while (printf("Choose plane: xy(1 2), xz (1 3) or yz(2 3): "),
                        fflush(stdin), cin.clear(), !((cin >> d1 >> d2).good()))
                    printf("ERROR: incorrect input. Try again\n");

                printf("Angle: %lg\n", v->Angle(d1, d2));

                system("pause");
                break;

            case 6:  // Multiply by number
                while (printf("Choose vector: "),
                        fflush(stdin), cin.clear(), !((cin >> arg).good()) || arg > list.Count())
                    printf("ERROR: incorrect input. Try again\n");
                v = (Vector *)list.GetItem(arg-1);

                while (printf("Enter number: "),
                        fflush(stdin), cin.clear(), !((cin >> val6).good()))
                    printf("ERROR: incorrect input. Try again\n");

                v->MultiplyByNumber(val6);
                v->Print();
                system("pause");
                break;

            case 7:  // Division by number
                while (printf("Choose vector: "),
                        fflush(stdin), cin.clear(), !((cin >> arg).good()) || arg > list.Count())
                    printf("ERROR: incorrect input. Try again\n");
                v = (Vector *)list.GetItem(arg-1);

                while (printf("Enter number: "),
                        fflush(stdin), cin.clear(), !((cin >> arg).good()))
                    printf("ERROR: incorrect input. Try again\n");

                v->DivisionByNumber(arg);
                v->Print();
                system("pause");
                break;

            case 8:  // Scalar Multiply
                while (printf("Input vectors indexes: "),
                        fflush(stdin), cin.clear(), !((cin >> a >> b).good()) || a > list.Count()
                                                                              || b > list.Count())
                    printf("ERROR: incorrect input. Try again\n");

                cout << "Scalar multiply: " << list.ScalarMultiply(a, b) << endl;
                system("pause");
                break;

            case 9:  // Vector Multiply
                while (printf("Input vectors indexes: "),
                        fflush(stdin), cin.clear(), !((cin >> a >> b).good()) || a > list.Count()
                                                    || b > list.Count())
                    printf("ERROR: incorrect input. Try again\n");

                cout << "vector multiply: " << list.VectorMultiply(a, b) << endl;
                system("pause");
                break;

            case 10:  // Summary of vectors
                while (printf("Input vectors indexes: "),
                        fflush(stdin), cin.clear(), !((cin >> a >> b).good()) || a > list.Count()
                                                                              || b > list.Count())
                    printf("ERROR: incorrect input. Try again\n");

                if(list[a-1].GetSize() != list[b-1].GetSize())
                    break;

                list.Summary(a, b)->Print();
                system("pause");
                break;

            case 11:  // Subtract of vectors
                while (printf("Input vectors indexes: "),
                        fflush(stdin), cin.clear(), !((cin >> a >> b).good()) || a > list.Count()
                                                                              || b > list.Count())
                    printf("ERROR: incorrect input. Try again\n");

                if(list[a-1].GetSize() != list[b-1].GetSize())
                    break;

                list.Subtracting(a, b)->Print();
                system("pause");
                break;

            case 12:  // Vectors equal
                while (printf("Input vectors indexes: "),
                        fflush(stdin), cin.clear(), !((cin >> a >> b).good()) || a > list.Count()
                                                                              || b > list.Count())
                    printf("ERROR: incorrect input. Try again\n");

                list.Compare(a, b) ? cout << "Vectors are equal\n"
                               : cout << "Vectors are not equal\n";
                system("pause");
                break;

            case 13:  // Collinearity of vectors
                while (printf("Input vectors indexes: "),
                        fflush(stdin), cin.clear(), !((cin >> a >> b).good()) || a > list.Count()
                                                                              || b > list.Count())
                    printf("ERROR: incorrect input. Try again\n");
                list.Collinearity(a, b) ? cout << "Vectors are collinear\n"
                                    : cout << "Vectors are not collinear\n";
                system("pause");
                break;

            case 14:  // Orthogonality of vectors
                while (printf("Input vectors indexes: "),
                        fflush(stdin), cin.clear(), !((cin >> a >> b).good()) || a > list.Count()
                                                                              || b > list.Count())
                    printf("ERROR: incorrect input. Try again\n");
                list.Orthogonality(a, b) ? cout << "Vectors are orthogonal\n"
                                     : cout << "Vectors are not orthogonal\n";
                system("pause");
                break;

            case 15:  // Belonging one vector to another
                while (printf("Input vectors indexes: "),
                        fflush(stdin), cin.clear(), !((cin >> a >> b).good()) || a > list.Count()
                                                                              || b > list.Count())
                    printf("ERROR: incorrect input. Try again\n");
                list.VectorAffiliation(a, b) ? cout << "Vectors 1 belongs to vector 2\n"
                                             : cout << "Vectors 1 do not belong to vector 2\n";
                system("pause");
                break;

            case 16:  // Belonging vector to a plane
                while (printf("Choose vector: "),
                        fflush(stdin), cin.clear(), !((cin >> index).good()) || arg > list.Count())
                    printf("ERROR: incorrect input. Try again\n");

                while (printf("Enter plane coefficients (A, B, C): "),
                        fflush(stdin), cin.clear(), !((cin >> a >> b >> c).good()))
                    printf("ERROR: incorrect input. Try again\n");

                list.PlaneAffiliation(index, a, b, c) ? cout << "Vector belong to plane\n"
                                                      : cout << "Vector did not belong to plane\n";
                system("pause");
                break;

            case 17:  // Replace vector
                while (printf("Choose vector: "),
                        fflush(stdin), cin.clear(), !((cin >> arg).good()) || arg > list.Count())
                    printf("ERROR: incorrect input. Try again\n");
                v1 = (Vector *)list.GetItem(arg-1);

                while (printf("Input vector norma: "),
                        fflush(stdin), cin.clear(), !((cin >> arg).good()))
                    printf("ERROR: incorrect input. Try again\n");

                v2 = new Vector(arg);
                v2->Input();

                cout << "Vector 1: ";
                v1->Print();
                cout << "Vector 2: ";
                v2->Print();
                *v1 = *v2;
                cout << "Replaced vector 1: ";
                v1->Print();

                system("pause");
                break;

            case 18:
                while (printf("Choose vector: "),
                        fflush(stdin), cin.clear(), !((cin >> arg).good()) || arg > list.Count())
                    printf("ERROR: incorrect input. Try again\n");
                v = (Vector *)list.GetItem(arg-1);

                cout << "Vector in origin format: ";
                v->Print();
                cout << "Vector in string format: " << v->ToString() << endl;

                system("pause");
                break;

            case 0:  // Exit
                return 0;

            default:
                cout << "Something wrong. Try again\n";
        }
    } while(true);
}
