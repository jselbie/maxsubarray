// Dynamic solution for the "max sum array" problem.  This is a small improvement over the "no cache" solution, but still
// hits a time limit exceeded error on large input sets.
// It introduces a "cache" of previously cached recursion results to avoid going down a recurive path redundantly.

class Solution {
public:

    vector<int>* pNums;
    typedef unordered_map<uint64_t, int> CACHE;
    CACHE cache;
    
    int maxSubArrayImpl(size_t pos, int sum) {

        const vector<int>& nums = *pNums;

        uint64_t key = (((uint64_t)pos) << 32) | ((uint32_t)((int32_t)sum));
        auto itor = cache.find(key);
        if (itor != cache.end()) {
            return itor->second;
        }

        if (pos >= nums.size()) {
            cache[key] = sum;
            return sum;
        }

        // option 1: Select nums[pos] for inclusion in the current subarray and continue to the next element
        int option1 = maxSubArrayImpl(pos + 1, sum + nums[pos]);

        // option 2: Accumulate if positive. Stop recursing regardless
        int option2 = sum + ((nums[pos] > 0) ? nums[pos] : 0);
        if (pos == 0) {
            option2 = nums[pos]; // for the single element array case
        }

        // option 3: select nums[pos] as a standalone sub-array and stop
        int option3 = nums[pos];

        // option 4: accumulate, but start a new subarray at this point
        int option4 = maxSubArrayImpl(pos + 1, nums[pos]);

        int tmp1 = (option1 > option2) ? option1 : option2;
        int tmp2 = (option3 > option4) ? option3 : option4;
        int result = (tmp1 > tmp2) ? tmp1 : tmp2;

        cache[key] = result;
        return result;
    }


    int maxSubArray(vector<int>& nums) {
        pNums = &nums;
        return maxSubArrayImpl(0, 0);
    }
};