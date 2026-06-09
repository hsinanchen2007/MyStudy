### 解题思路
此处撰写解题思路
DP
### 代码

```cpp
class Solution {
public:
    int max(int a,int  b){
        return a>b?a:b;
    }
    int dp[59];
    int cuttingRope(int n) {
       dp[1]=1;
       for(int i=2;i<=58;i++)dp[i]=i-1;
       for(int i=3;i<=n;i++){
           for(int j=2;j<=(i>>1);j++){
               dp[i]=max(dp[i],max(dp[j],j)*max(dp[i-j],i-j));
           }
       }
       return dp[n];
    }
};
```