### 题目描述
给你一个整数数组 nums ，请你找出数组中乘积最大的连续子数组（该子数组中至少包含一个数字）。

示例 1:
输入: [2,3,-2,4]
输出: 6
解释: 子数组 [2,3] 有最大乘积 6。
示例 2:

输入: [-2,0,-1]
输出: 0
解释: 结果不能为 2, 因为 [-2,-1] 不是子数组。


### 解题思路
动态规划。
记录当前最大值curMax和最小值curMin，持续更新最终的最大值ret。
如果遇到负数，最大值变成最小值了，需要swap。

### 代码

```cpp
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) { return 0; }
        int ret = INT_MIN;
        int curMax = 1, curMin = 1;
        for (auto n : nums) {
            if (n < 0) {
                swap(curMax, curMin);
            }
            curMax = max(curMax * n, n);
            curMin = min(curMin * n, n);
            ret = max(curMax, ret);
        }
        return ret;
    }
};
```