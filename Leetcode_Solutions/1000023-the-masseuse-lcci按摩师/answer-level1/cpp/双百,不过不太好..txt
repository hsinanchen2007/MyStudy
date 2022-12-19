### 解题思路
此处撰写解题思路

### 代码

```cpp
int dp[10000][2]={0};
class Solution {
public:
    int massage(vector<int>& nums) {
        int n = (int)nums.size();
        if(n==0) return 0;
        memset(dp,0,sizeof dp);
        dp[0][0]=0;
        dp[0][1] =nums[0];
        for(int i = 1;i<n;i++){
            dp[i][0]= max(dp[i-1][1],dp[i-1][0]);
            dp[i][1] = dp[i-1][0]+nums[i];
        }
        return max(dp[n-1][0],dp[n-1][1]);
    }
};
```