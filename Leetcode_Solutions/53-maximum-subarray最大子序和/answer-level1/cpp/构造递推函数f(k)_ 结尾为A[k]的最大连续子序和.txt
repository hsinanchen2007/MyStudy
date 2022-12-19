### 解题思路
这道题目想了我很久
一开始的思路是定义f(k)为数组中前k个数中最大连续子序和
由于下面的case，感觉都无法构造递推公式
1. [1,-3,4]
这道题的关键还是连接f(k)与f(k-1)
如何连接？
定义f(k)为结尾为A[k]的最大连续子序和
那么有f(k) = max(f(k-1) + A[k], A[k]);
维护一个数组dp，得到以每个idx为结尾的最大连续子序和，然后遍历dp可以得到最大的整个数组的子序列和


### 代码

```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        for(int i = 1; i < nums.size(); ++i){
            if(dp[i-1] >= 0){
                dp[i] = dp[i-1] + nums[i];
            }else{
                dp[i] = nums[i];
            }
        }
        int res = INT_MIN;
        for(int i = 0; i < dp.size(); ++i){
            res = max(res, dp[i]);
        }
        return res;
    }
};
```

### 结果
执行用时 : 12 ms , 在所有 C++ 提交中击败了 44.51% 的用户 
内存消耗 : 7.1 MB , 在所有 C++ 提交中击败了 100.00% 的用户