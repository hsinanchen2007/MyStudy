**解题思路**

- **二叉树特点**:根节点，左子树，右子树
- **二叉搜索树特点**：左 < 根 < 右

假设有**n**个节点，当**x**为根节点时，左子树有 **(x-1)** 个节点，右子树有 **(n-x)** 个节点，在此情况下可构造 **f(x-1) * f(n-x)** 种二叉搜索树，由此可得当有n个节点时，总共有：**∑f(x,n), (x=1,2...,n)** 种二叉搜索树。


**代码如下：**
```
int numTrees(int n){
    int dp[n+1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            dp[i] += dp[j-1]*dp[i-j];
        }
    }
    return dp[n];
}
```


![image.png](https://pic.leetcode-cn.com/785d6045841d6bc41ea6b1e390d2937d6a7b1d5dee2d410b0e9e84756b087e3d-image.png)
