### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
     // 用树状数组找到在小于当前数字的数中，递增序列长度的最大值。(类似区间极大值)
        // 树状数组求区间极大值时，只要区间是从 1 开始的，就可以直接用区间和的思路
        vector<int> numsort(nums.begin(), nums.end());
        sort(numsort.begin(), numsort.end());
        int tree[nums.size() + 1] = {0}, res = 0;
        for(int i : nums)
        {
            int before = 0;
            int rk = lower_bound(numsort.begin(), numsort.end(), i) - numsort.begin();
            for(int t = rk; t > 0; t -= ((t) & (-t))) before = max(before, tree[t]);
            res = max(res, before + 1);
            for(int t = rk + 1; t <= nums.size(); t += ((t) & (-t))) tree[t] = max(tree[t],                 before + 1);
        }
        return res;
    }
};
```