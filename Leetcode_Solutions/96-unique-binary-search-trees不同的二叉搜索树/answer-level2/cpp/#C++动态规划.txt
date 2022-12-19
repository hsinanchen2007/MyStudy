# C++动态规划
   忘了考虑二叉树的节点异构。
对于**n**个节点生成二叉树，挑选**第j个**为根节点，第1——j-1个节点生成**左子树**，第j+1第n个节点**右子树**，那么选取第**j**个为根节点的二叉树的个数为：dp[j-1]*dp[n-j]...形成动态规划
### 代码

```cpp
class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1,0);
        dp[0]=1;dp[1]=1;
        for (int i = 2; i <= n; ++i) {
            for (int j=1; j <=i; ++j) //选取根节点为j
                dp[i] += dp[j-1]*dp[i-j];
        }
        return dp[n];
    }
};

```