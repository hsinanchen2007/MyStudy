### 解题思路
dp[i]表示从0到当前这个位置能获得的最大的时间
![image.png](https://pic.leetcode-cn.com/2222eb0b267edcdc5c6fa02c1b4bb3f46517b787d8bd583cc0684ed2293bf506-image.png)


### 代码

```cpp
class Solution {
public:
    int massage(vector<int>& nums) {
        if(nums.size()==0) return 0;
        vector<int> dp(nums.size());
        for(int i=0;i<nums.size();i++){
            if(i==0) dp[i]=nums[i];
            else if(i==1) dp[i]=max(nums[i-1],nums[i]);
            else{
                dp[i]=max(dp[i-1],dp[i-2]+nums[i]);
            }
        }
        return dp[nums.size()-1];
    }
};
```