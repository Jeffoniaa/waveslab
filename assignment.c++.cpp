#include <iostream>
#include <vector>
#include <cmath>
#include <map>

using namespace std;

vector<int> get_max_network_quality(vector<vector<int>>& towers, int radius) {
    map<pair<int, int>, int> network_quality;
    int max_quality = 0;
    vector<int> max_coord = {0, 0};

    for (auto tower : towers) {
        int x = tower[0], y = tower[1], q = tower[2];
        for (int i = x - radius; i <= x + radius; i++) {
            for (int j = y - radius; j <= y + radius; j++) {
                if (network_quality.find({i, j}) == network_quality.end()) {
                    double d = sqrt(pow(i - x, 2) + pow(j - y, 2));
                    if (d <= radius) {
                        int signal_quality = q / (1 + d);
                        network_quality[{i, j}] = signal_quality;
                        if (signal_quality > max_quality) {
                            max_quality = signal_quality;
                            max_coord = {i, j};
                        } else if (signal_quality == max_quality && max_coord > vector<int>{i, j}) {
                            max_coord = {i, j};
                        }
                    }
                }
            }
        }
    }

    return max_coord;
}

int main() {
    vector<vector<int>> towers = {{1, 2, 5}, {2, 1, 7}, {3, 1, 9}};
    int radius = 2;
    vector<int> max_coord = get_max_network_quality(towers, radius);
    cout << "[" << max_coord[0] << ", " << max_coord[1] << "]" << endl;
    return 0;
}