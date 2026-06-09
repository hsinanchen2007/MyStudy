### 描述

这里给出一份我的动态规划+二分的简短版C++代码，供参考

### 代码

```cpp
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        const int n = nums.size();
        vector<int> seq;
        for (int i = 0; i < n; i++) {
            auto it = lower_bound(seq.begin(), seq.end(), nums[i]);
            if (it == seq.end()) {
                seq.push_back(nums[i]);
            } else {
                *it = nums[i];
            }
        }
        return int(seq.size());
    }
};
```