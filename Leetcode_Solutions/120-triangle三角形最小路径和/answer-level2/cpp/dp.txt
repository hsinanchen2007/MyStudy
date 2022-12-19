### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> dp;
    int minimumTotal(vector<vector<int>>& triangle) {
        int len=triangle.size();
        vector<vector<int>> dp(len,vector<int>(len));
        for(int i=0;i<len;++i){
            dp[len-1][i]=triangle[len-1][i];
        }
        for(int i=len-2;i>=0;--i){
            for(int j=0;j<=i;++j){
                dp[i][j]=min(dp[i+1][j],dp[i+1][j+1])+triangle[i][j];
            }
        }
        return dp[0][0];
    }
};
```