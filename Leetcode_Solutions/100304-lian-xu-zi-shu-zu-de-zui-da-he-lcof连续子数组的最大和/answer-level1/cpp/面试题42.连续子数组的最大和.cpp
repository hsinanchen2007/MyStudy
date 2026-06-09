### 解题思路
- 核心思路：动态规划，**dp[i]表示以nums[i]为结尾的连续子数组的最大和**，若dp[i-1]>0，dp[i]=nums[i-1]+nums[i]，否则dp[i]=nums[i]（实际代码中dp与nums可以共用一个数组），预设一个result变量，记录遍历过程中的最大值
- 执行用时：52 ms, 在所有 C++ 提交中击败了5.79%的用户
- 内存消耗：22.8 MB, 在所有 C++ 提交中击败了100.00%的用户
### 代码

```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int result=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]>0)nums[i]=nums[i-1]+nums[i];
            result=max(result,nums[i]);
        }
        return result;
    }
};
```