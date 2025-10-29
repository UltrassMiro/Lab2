#include "vector.h"
using namespace std;

int main() {
    vector<Vector> vec;   // generic collection
    list<Vector> lst;     // non-generic collection
    Vector arr[3];        // array

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
        cout << "7. Show binary tree (Preorder)\n";
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
                cout << "Sorted by length:\n";
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
                BinaryTree<Vector> tree;

                for (auto& v : vec) tree.insert(v);
                for (auto& v : lst) tree.insert(v);
                for (auto& v : arr) tree.insert(v);

                cout << "\nPreorder traversal using method:\n";
                tree.preorder();

                cout << "\nPreorder traversal using iterator:\n";
                for (auto& v : tree) {
                    v.print();
                    cout << " | length = " << v.length() << endl;
                }
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
