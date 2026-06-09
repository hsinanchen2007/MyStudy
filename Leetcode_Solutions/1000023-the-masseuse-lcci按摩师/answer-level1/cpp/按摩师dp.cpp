### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int massage(vector<int>& nums) {
        int size=nums.size();
        if(size==0)
            return 0;
        vector<int>dp(size+1);
        dp[1]=nums[0];
        for(int i = 2;i <=size; i++){
            dp[i] = max(dp[i-1],dp[i-2]+nums[i-1]);
        }
        return dp[size];
    }
};
```