```cpp
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.empty()) return 0;
        int base = 0, maxLen = 1;
        int i = 1;
        for (; i < nums.size(); i++) {
            if (nums[i] <= nums[i-1]) {
                maxLen = max(i-base, maxLen);
                base = i;
            }
        }
        maxLen = max(i-base, maxLen);
        return maxLen;
    }
};
```