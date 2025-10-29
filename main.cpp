#include "vector.h"

using namespace std;

int main() {
    vector<Vector> vec;
    int choice;
    bool running = true;

    while (running) {
        cout << "\n=== VECTOR OPERATIONS MENU ===\n";
        cout << "1. Add vector\n";
        cout << "2. Delete vector\n";
        cout << "3. Update vector\n";
        cout << "4. Search vector by length\n";
        cout << "5. Display all vectors\n";
        cout << "6. Exit\n";
        cin >> choice;

        switch (choice) {
            case 1: {
                double x, y, z;
                cout << "Enter coordinates (x y z):\n";
                cin >> x >> y >> z;
                vec.push_back(Vector(x, y, z));
                cout << "Vector added successfully.\n";
                break;
            }

            case 2: {
                int index;
                print_all(vec);
                cout << "Enter element number to delete:\n";
                cin >> index;
                if (index > 0 && index <= (int)vec.size()) {
                    vec.erase(vec.begin() + index - 1);
                    cout << "Vector deleted.\n";
                } else cout << "Invalid index.\n";
                break;
            }

            case 3: {
                int index;
                print_all(vec);
                cout << "Enter element number to update:\n";
                cin >> index;
                if (index > 0 && index <= (int)vec.size()) {
                    double x, y, z;
                    cout << "Enter new coordinates (x y z): ";
                    cin >> x >> y >> z;
                    vec[index - 1].update(x, y, z);
                    cout << "Vector updated.\n";
                } else cout << "Invalid index.\n";
                break;
            }

            case 4: {
                double target;
                cout << "Enter minimum length for search:\n";
                cin >> target;

                bool found = false;
                cout << "Vectors with length >= " << target << ":\n";
                for (const auto& v : vec) {
                    if (v.length() >= target) {
                        v.print();
                        cout << " | length = " << v.length() << endl;
                        found = true;
                    }
                }

                if (!found) {
                    cout << "No vectors with length >= " << target << " found.\n";
                }
                break;
            }
            case 5:
                print_all(vec);
                break;

            case 6:
                running = false;
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Unknown command.\n";
        }
    }
    return 0;
}
