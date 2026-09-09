/**
 * @file remove_duplicates.cpp
 * @brief Removes duplicates from a sorted array in-place using Two Pointers.
 *
 * Time Complexity: O(N) - Single pass through the array
 * Space Complexity: O(1) - Modifies the array in place without extra space.
 */

#include <iostream>
#include <vector>

using std::cout;
using std::vector;
int removeDuplicates(vector<int>& nums) {
    // Edge Case: If the array is empty, return 0
    if (nums.empty()) {
        return 0;
    }

    int uniqueIdx = 0;  // slow pointer

    for (int exploreIdx = 1; exploreIdx < nums.size(); ++exploreIdx) {
        // If we find a new unique element
        if (nums[exploreIdx] != nums[uniqueIdx]) {
            uniqueIdx++;
            nums[uniqueIdx] = nums[exploreIdx];
        }
    }

    return uniqueIdx + 1;  // returns the number of unique elements
}

int main() {
    vector<int> nums = {1, 1, 2, 2, 3};

    cout << "Original array: ";
    for (int num : nums) cout << num << " ";
    cout << "\n";

    int uniqueCount = removeDuplicates(nums);

    // print the result
    cout << "Number of unique elements: " << uniqueCount << "\n";

    cout << "Modified Array: ";
    for (int i = 0; i < uniqueCount; ++i) {
        cout << nums[i] << " ";
    }
    cout << "\n";
    return 0;
}
