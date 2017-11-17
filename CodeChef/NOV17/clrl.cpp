#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    int n, reziba;
    while(t--) {
        cin >> n >> reziba;
        int ratings[n];
        int ratings_sorted[n];
        for (int i = 0; i < n; i++) {
            cin >> ratings[i];
            ratings_sorted[i] = ratings[i];
        }
        // sort(ratings_sorted, ratings_sorted + n);

        int max_possible = 2000000000;
        int least_possible = 0;
        int iter_end = n - 1;
        bool result = true;
        for (int i = 0; i < iter_end; i++) {
            if (ratings[i] > max_possible || ratings[i] < least_possible) {
                // cout << "Entering false condition" << endl;
                result = false;
                break;
            }
            if (ratings[i] > ratings[i + 1]) {
            // checking if correct directions are entered or not. 
            // might be that chef noted wrong directions on the paper
                if (reziba > ratings[i]) {
                    result = false;
                    break;
                }
            max_possible = ratings[i];
            // cout << "max possible is now " << ratings[i] << endl;
            } else if (ratings[i] < ratings[i + 1]) {
                if (reziba < ratings[i]) {
                    result = false;
                    break;
                }
                least_possible = ratings[i];
                // cout << "min possible is now " << ratings[i] << endl;
            }
        }

        if (result) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}