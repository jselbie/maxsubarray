#include <vector>
using namespace std;

class Solution {
public:
    vector<int> makeSumArray(const vector<int>& nums) {
        int prev = 0;
        vector<int> sums;

        for (auto value : nums) {
            sums.push_back(prev + value);
            prev = prev + value;
        }

        return sums;
    }

    int maxSubArray(vector<int>& nums) {

        // STEP 1: scan nums for the pathological case of all negative numbers
        // If it's all negative numbers, just return the highest value found

        if (nums.size() == 0) {
            return 0;
        }

        int positiveCount = 0;
        int highest = nums[0];

        for (size_t i = 0; i < nums.size() && positiveCount==0; i++) {
            positiveCount += (nums[i] > 0);
            highest = std::max(highest, nums[i]);
        }

        if (positiveCount == 0) {
            return highest;
        }

        // Step 2: Make a summation array such that sums.size() == nums2.size() and sums[j] == (nums[0]+num[1]+...sums[i])
        auto sums = makeSumArray(nums);

        // Step 3: Scan the summation array. Each time a new minimum value is found, mark it as the lowest
        // We're trying to find the biggest diff between a local minimum and a subsequent local maxima
        int lowest = 0;
        int bestDiff = 0;
        for (int value : sums) {
            if (value <= lowest) {
                lowest = value;
            }
            else {
                int diff = value - lowest;
                bestDiff = std::max(diff, bestDiff);
            }
        }

        return bestDiff;
    }

};