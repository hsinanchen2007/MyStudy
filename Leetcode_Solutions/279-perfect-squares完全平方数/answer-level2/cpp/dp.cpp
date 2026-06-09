### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    const int inf=999999999;
    vector<int> dp;
    int numSquares(int n) {
       dp.resize(n+1);
       dp[1]=1;
       for(int i=2;i<=n;++i){
           dp[i]=inf;
           for(int j=1;j*j<=i;++j){
               dp[i]=min(dp[i],dp[i-j*j]+1);
           }
       }
       return dp[n];
    }
};
```