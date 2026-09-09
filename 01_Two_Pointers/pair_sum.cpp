#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::sort;
using std::vector;

bool findPairWithSum(vector<int>& v, int target) {
    if (v.size() < 2) {
        return false;
    }
    sort(v.begin(), v.end());
    size_t left = 0;
    size_t right = v.size() - 1;

    while (left < right) {
        long long sum = static_cast<long long>(v[left] + v[right]);  // to prevent overflow
        if (sum == target) {
            cout << "Found at indices: " << left << " and " << right;
            return true;
        } else if (sum > target) {
            right--;
        } else {
            left++;
        }
    }

    return false;
}

int main() {
    vector<int> v = {2, 7, 11, 13};
    int target = 9;

    bool found = findPairWithSum(v, target);

    if (!found) {
        cout << "Not found." << endl;
    }

    return 0;
}
