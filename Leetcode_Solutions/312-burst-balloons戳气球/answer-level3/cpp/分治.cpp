### 解题思路
先是用回溯算法做，遍历所有解，然后求最大值，但是超时。
改用分治，与回溯的最大区别是回溯先找气球戳破，分治先找气球保留，然后再去找左右两边的分组中的气球。
为什么是保留气球，而不是戳破气球，主要原因就是戳破气球会破坏分组的状态，而保留气球，分组状态不会改变。

### 代码

```cpp
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        vector<vector<int>> cache(nums.size(), vector<int>(nums.size(), -1));
        int result = maxCoinsHelper(nums, 0, nums.size() - 1, cache);
        return result;
    }

    int maxCoinsHelper(vector<int>& nums, int start, int end, vector<vector<int>>& cache) {
        if (start <= end && cache[start][end] != -1) {
            return cache[start][end];
        }
        if (start == end) {
            int res = (start - 1 < 0 ? 1 : nums[start - 1]) * nums[start] * (end + 1 > nums.size() - 1 ? 1 : nums[end + 1]);
            return res;
        }
        int maxCoins = 0;
        int tmp = 0;
        for (int i = start; i <= end; i++) {
            tmp = (start - 1 < 0 ? 1 : nums[start - 1]) * nums[i] * (end + 1 > nums.size() - 1 ? 1 : nums[end + 1]) + maxCoinsHelper(nums, start, i - 1, cache) + maxCoinsHelper(nums, i + 1, end, cache);
            maxCoins = max(tmp, maxCoins);
        }
        if (start <= end) {
            cache[start][end] = maxCoins;
        }
        return maxCoins;
    }
};
```