#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    string input;
    while(t--) {
        cin >> input;

        char last_seen = '.';
        int a = 0, b = 0;
        for (int i = 0; input[i] != '\0'; i++) {
            if (input[i] == 'A'){
                a++;
                last_seen = 'A';
            } 
            else if (input[i] == 'B'){
                b++;
                last_seen = 'B';
            } else {
                // encountered a .
                int dots = 0;
                while(input[i] == '.'){
                    dots++;
                    i++;
                }
                if (input[i] == last_seen) {
                    if (last_seen == 'A') a += dots;
                    else b += dots;
                }

                i--; // reducing it back as it will increase in the loop again
            }

        }

        cout << a << ' ' << b << endl;



    }


    return 0;
}