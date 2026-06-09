### 解题思路
这道题很容易让我们联想到dp，一般我们通常想到的就是定义dp[n]表示长度为n的绳子的最大值，
然后简单的列出dp方程式为dp[i]=max(dp[i],dp[j]*(i-j)),j的取值为1到i-1，但是当我们提交时发现错了
这里最关键的一点dp[j]一定是分成大于等于2份的，因此漏掉了一种情况，即将j当作一份，不分割，
因此最后的方程式为dp[i]=max(dp[i],max(dp[j]*(i-j),j*(i-j)));

### 代码

```cpp
class Solution {
public:
    int cuttingRope(int n) {
        vector<int> dp(n+1,1);
        for(int i=3;i<=n;i++)
        {
            for(int j=1;j<i;j++)
                dp[i]=max(dp[i],max(dp[j]*(i-j),j*(i-j)));
        }
        return dp[n];
    }
};
```