class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<long long> numsTmp;
        numsTmp.push_back(static_cast<long long>(lower) - 1);
        for (int i = 0; i < nums.size(); i++) {
            numsTmp.push_back(nums[i]);
        }
        numsTmp.push_back(static_cast<long long>(upper) + 1);
        vector<string> result;
        for (int i = 1; i < numsTmp.size(); i++) {
            long long diff = numsTmp[i] - numsTmp[i - 1];
            if (diff == 2) {
                result.push_back(to_string(numsTmp[i] - 1));
            } else if (diff > 2) {
                result.push_back(to_string(numsTmp[i - 1] + 1) + "->" + to_string(numsTmp[i] - 1));
            }
        }
        return result;
    }
};