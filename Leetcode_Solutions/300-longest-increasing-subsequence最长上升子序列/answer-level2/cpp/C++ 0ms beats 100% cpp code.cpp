```cpp
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty()) return 0;
        vector<int> LIS;
        for (int val: nums) {
            auto it = lower_bound(LIS.begin(), LIS.end(), val);
            if (it == LIS.end()) LIS.push_back(val);
            else {
                int pos = distance(LIS.begin(), it);
                LIS[pos] = val;
            }
        }
        return LIS.size();
    }
};
```