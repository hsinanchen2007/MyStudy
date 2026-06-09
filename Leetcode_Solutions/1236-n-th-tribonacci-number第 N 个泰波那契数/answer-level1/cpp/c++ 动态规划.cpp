### 解题思路
直接递归会超时，所以需要优化一下。
动态规划
递推式已经给出，用dp数组存一下计算过的泰波那契数。

![1.png](https://pic.leetcode-cn.com/7a867318665f1f35f36a7e945d680cb8167dbfa8b682b983b74be482b061abe2-1.png)


### 代码

```cpp
class Solution {
public:
    int tribonacci(int n) {
        int dp[38];
        dp[0]=0; dp[1]=1; dp[2]=1;
        
        for(int i=3;i<=n;i++)
            dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
        
        return dp[n];
    }
};
```