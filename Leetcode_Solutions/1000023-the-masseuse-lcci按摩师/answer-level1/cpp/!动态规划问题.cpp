### 解题思路
动态规划问题，思路是以每一个元素为结尾时，“取它”或“不取它”的最大值，转移方程在程序里。

### 代码

```cpp
class Solution {
public:
    int massage(vector<int>& nums) {
        //动态规划，dp[i]=max(dp[i-2]+nums[i], dp[i-1])
        if (nums.size()==0) return 0;
        if (nums.size()==1) return nums[0];
        vector<int> dp(nums.size(), 0);//初始化dp数组
        dp[0]=nums[0];
        dp[1]=max(nums[0], nums[1]);
        for (int i=2; i<nums.size(); i++){
            dp[i]=max(dp[i-2]+nums[i], dp[i-1]);
        }
        return dp[nums.size()-1];
    }
};
```