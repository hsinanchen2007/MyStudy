### 解题思路
数组dp用来存储以数组nums中位置为i的元素结尾的最大和子序列。dp[0]=nums[0]，dp[i]=nums[i]>(nums[i]+dp[i-1]) ? nums[i]:(nums[i]+dp[i-1])。最后遍历数组dp，找出值最大的元素即为所求。

### 代码

```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
     //动态规划算法求解
     vector<int>& dp = nums;
     int temp = 0;
     int max = dp[0];

     for (int i = 1; i < nums.size(); i++){
         temp = dp[i-1] + nums[i];
         if(temp > nums[i]) dp[i] = temp;
     } 
     for (int i = 1; i < nums.size(); i++){
         max = dp[i] > max ? dp[i] : max;
     } 

     return max; 
    }
};
```