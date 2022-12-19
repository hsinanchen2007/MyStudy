### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size()+1);
        if(nums.size()<2) return nums.size();
        int max=0;
        dp[0]=0;
        dp[1]=1;
        for(int i=2;i<=nums.size();i++){
            dp[i]=1;
            for(int j=1;j<i;j++){
                if(nums[j-1]<nums[i-1] && dp[j]+1>dp[i]) dp[i] = dp[j]+1;
            }
        }

        for(int i=0;i<=nums.size();i++){
            if(dp[i]>max) max=dp[i];
        }

        return max;
    }


};
```