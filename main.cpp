#include "vector.h"
using namespace std;

int main() {
    vector<Vector> vec;   // Generic коллекция
    list<Vector> lst;     // Non-generic коллекция
    Vector arr[3];        // Массив из 3-х векторов

    int choice;
    bool running = true;

    while (running) {
        cout << "\n=== VECTOR OPERATIONS MENU ===\n";
        cout << "1. Add new vector (root)\n";
        cout << "2. Show all vectors\n";
        cout << "3. Add new list vector (left)\n";
        cout << "4. Show all list vectors\n";
        cout << "5. Add new array vector (right)\n";
        cout << "6. Show all array vectors\n";
        cout << "7. Update coordinates\n";
        cout << "8. Search vectors by minimum length\n";
        cout << "9. Show binary tree (Preorder)\n";
        cout << "0. Exit\n";
        cin >> choice;

        switch (choice) {
            case 1: {
                double x, y, z;
                cout << "Enter coordinates (x y z): ";
                cin >> x >> y >> z;
                vec.push_back(Vector(x, y, z));
                cout << "Vector has been added.\n";
                break;
            }

            case 2: {
                sort(vec.begin(), vec.end());
                print_all(vec);
                break;
            }

            case 3: {
                double x, y, z;
                cout << "Enter coordinates (x y z): ";
                cin >> x >> y >> z;
                lst.push_back(Vector(x, y, z));
                cout << "Vector added to std::list.\n";
                break;
            }

            case 4: {
                cout << "List traversal:\n";
                for (auto& v : lst) {
                    v.print(); cout << " | length = " << v.length() << endl;
                }
                break;
            }

            case 5: {
                cout << "Enter 3 vectors (x y z):\n";
                for (int i = 0; i < 3; i++) {
                    double x, y, z;
                    cin >> x >> y >> z;
                    arr[i] = Vector(x, y, z);
                }
                break;
            }

            case 6: {
                cout << "Array traversal:\n";
                for (auto& v : arr) {
                    v.print(); cout << " | length = " << v.length() << endl;
                }
                break;
            }

            case 7: {
                int typeChoice;
                cout << "Choose collection to update: 1-Vector, 2-List, 3-Array: ";
                cin >> typeChoice;

                int index;
                double x, y, z;
                switch(typeChoice) {
                    case 1:
                        print_all(vec);
                        cout << "Enter index to update: ";
                        cin >> index;
                        if(index > 0 && index <= (int)vec.size()) {
                            cout << "Enter new coordinates (x y z): ";
                            cin >> x >> y >> z;
                            vec[index-1].update(x, y, z);
                        } else cout << "Invalid index.\n";
                        break;

                    case 2: {
                        int i = 1;
                        for (auto& v : lst) {
                            cout << i << ": "; v.print(); cout << endl;
                            i++;
                        }
                        cout << "Enter index to update: ";
                        cin >> index;
                        if(index > 0 && index <= (int)lst.size()) {
                            i = 1;
                            for(auto& v : lst) {
                                if(i == index) {
                                    cout << "Enter new coordinates (x y z): ";
                                    cin >> x >> y >> z;
                                    v.update(x, y, z);
                                    break;
                                }
                                i++;
                            }
                        } else cout << "Invalid index.\n";
                        break;
                    }

                    case 3:
                        cout << "Array indices 1-3.\nEnter index to update: ";
                        cin >> index;
                        if(index >= 1 && index <= 3) {
                            cout << "Enter new coordinates (x y z): ";
                            cin >> x >> y >> z;
                            arr[index-1].update(x, y, z);
                        } else cout << "Invalid index.\n";
                        break;

                    default:
                        cout << "Unknown collection.\n";
                }
                break;
            }

            case 8: {
                double minLen;
                cout << "Enter minimum length: ";
                cin >> minLen;

                cout << "\nVectors in vector >= " << minLen << ":\n";
                for(auto& v : vec)
                    if(v.length() >= minLen) { v.print(); cout << " | length = " << v.length() << endl; }

                cout << "\nVectors in list >= " << minLen << ":\n";
                for(auto& v : lst)
                    if(v.length() >= minLen) { v.print(); cout << " | length = " << v.length() << endl; }

                cout << "\nVectors in array >= " << minLen << ":\n";
                for(auto& v : arr)
                    if(v.length() >= minLen) { v.print(); cout << " | length = " << v.length() << endl; }

                break;
            }

            case 9: {
                BinaryTree<Vector> tree;
                for(auto& v : vec) tree.insert(v);
                for(auto& v : lst) tree.insert(v);
                for(auto& v : arr) tree.insert(v);

                cout << "\nPreorder traversal using method:\n";
                tree.preorder();

                cout << "\nPreorder traversal using iterator:\n";
                for(auto& v : tree) { v.print(); cout << " | length = " << v.length() << endl; }
                break;
            }

            case 0:
                running = false;
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Unknown command.\n";
        }
    }

    return 0;
}
