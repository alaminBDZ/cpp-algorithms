#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long maxSumSubarray(const vector<int>& arr, int k) {
    int n = arr.size();
    if (n < k || k <= 0) {
        cout << "Invalid window size";
        return -1;
    }
    long long windowSum = 0;
    ;
    for (int i = 0; i < k; i++) {
        windowSum += arr[i];
    }
    long long maxSum = windowSum;
    for (int i = k; i < n; i++) {
        windowSum = windowSum + arr[k] - arr[i - k];

        maxSum = max(windowSum, maxSum);
    }

    return maxSum;
}

int main() {
    vector<int> arr = {2, 1, 5, 1, 3, 2};
    int k = 3;

    long long result = maxSumSubarray(arr, k);
    cout << "Continguous max subarray: " << result << endl;

    return 0;
}
