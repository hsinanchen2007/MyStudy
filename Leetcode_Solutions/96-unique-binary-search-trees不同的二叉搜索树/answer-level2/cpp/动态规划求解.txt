### 解题思路
对于本题，我们要想明白这样一个问题：对于n 当以i(1=<i<=n>)为根结点的时候 此时的路径数是该节点的左右子树的路径乘积，在这里我们要知道左右子树的路径数只和它们的长度有关，与他们的内容无关，而这些子树的长度是有重复的，所以利用动态规划解决。我们定义一个数组dp[]来记录每一个数字n的路径总数。


### 代码

```cpp
class Solution {
public:
    int numTrees(int n) {
        vector<int>dp(n+1,0);
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=n;i++)
        {
           for(int j=1;j<=i;j++)
           {
               dp[i]+=dp[j-1]*dp[i-j];
           }
        }
        return dp[n];
    }
};
```