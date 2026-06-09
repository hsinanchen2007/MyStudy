### 解题思路
动态规划= = 动态规划的题真的不熟练
首先要定义好状态方程，设dp[i]为第i个人时最长预约时间，状态转移方程是
//第一个i-1是指不预约当前时间，第二个i-2指的是预约当前时间，所以两个比较大小
另外由于dp当前只和上两个有关，所以可以省略空间，但注意要加上length == 2防止数组越界
dp[i]=max(dp[i-1],dp[i-2]+nums[i]) 

### 代码

```cpp
class Solution {
public:
    int massage(vector<int>& nums) {
    int length = nums.size();
    if(length == 0)
        return 0;
    if(length == 1)
        return nums[0];
    vector<int> dp(3,0);
    dp[0] = nums[0]; 
    dp[1] = max(nums[0],nums[1]);
    if(length == 2){
        return dp[1];
    }
    for(int i = 2 ;i <length;i++){
        dp[2] = max(dp[1],dp[0]+nums[i]);
        dp[0] = dp[1];
        dp[1] = dp[2];
    }
    return dp[2];
    }
};
```