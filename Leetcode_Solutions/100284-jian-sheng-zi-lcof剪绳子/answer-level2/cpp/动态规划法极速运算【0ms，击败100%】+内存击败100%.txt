### 解题思路
首先要找准动态规划的公式，比较容易想到的是 dp[i]=max(dp[i],dp[j]*dp[i-j]);但有个细节就是绳子存在不被切割但情况，在i比较小的时候if(i!=n) dp[i] = max(dp[i],i);式子尤为关键！

### 代码

```cpp
class Solution {
public: 
int dp[60]={0};
int cuttingRope(int n) {
    dp[1]=1;
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<i;j++)
        {
            dp[i]=max(dp[i],dp[j]*dp[i-j]);
        }
        if(i!=n) dp[i] = max(dp[i],i);
    }
    return dp[n];
}
        

    
};
```