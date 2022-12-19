### 解题思路
给定一个有序序列 1 ... n，为了根据序列构建一棵二叉搜索树。我们可以遍历每个数字 i，将该数字作为树根，1 ... (i-1) 序列将成为左子树，(i+1) ... n 序列将成为右子树。于是，我们可以递归地从子序列构建子树

### 代码

```cpp
class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1,0);
        dp[0]=1;dp[1]=1;
        for(int i=2;i<=n;i++){//dp【i】前i个数所能组成儿茶树的个数
            for(int j=1;j<=i;j++){//以1~i之间取j作为根，其左右子树种数相乘，累加
                dp[i]+=dp[j-1]*dp[i-j];
            }
        }
        return dp[n];
    }
};
```