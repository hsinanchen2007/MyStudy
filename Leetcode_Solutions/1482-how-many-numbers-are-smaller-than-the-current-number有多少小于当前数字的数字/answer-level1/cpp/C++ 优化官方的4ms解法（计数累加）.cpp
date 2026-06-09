```cpp
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> cnt(102, 0);
        for (auto num : nums)
            ++cnt[num + 1];

        for (int i = 1; i < cnt.size(); ++i)
            cnt[i] += cnt[i - 1];

        for (int i = 0; i < nums.size(); ++i)
            nums[i] = cnt[nums[i]];
        return nums;
    }
};
```