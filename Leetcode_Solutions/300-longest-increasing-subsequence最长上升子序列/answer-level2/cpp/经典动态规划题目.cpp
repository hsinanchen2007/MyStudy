### 解题思路
写出dp[i]的状态更新方程

### 代码

```cpp
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size()==0) return 0;
        if (nums.size()==1) return 1;
        vector<int> dp;//动态规划数组
        dp.push_back(1);
        int re=1;
        for (int i=1; i<nums.size(); i++){
            dp.push_back(1);//初试值
            for(int j=0; j<i; j++){
                if (nums[j]<nums[i] && dp[j]+1>dp[i]) dp[i]=dp[j]+1;//找到前面的可满足的最大的值，然后把它+1
            }
            re=max(re,dp[i]);
        }
        return re; 
    }
};
```