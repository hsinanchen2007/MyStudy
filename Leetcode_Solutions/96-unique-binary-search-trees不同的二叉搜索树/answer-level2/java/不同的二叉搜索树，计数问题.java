### Leetcode 96 不同的二叉搜索树

给定一个整数 *n*，求以 1 ... *n* 为节点组成的二叉搜索树有多少种？

<a href = "https://leetcode-cn.com/problems/unique-binary-search-trees/">题目描述</a>

本质上是计数问题：

以不同的节点作为根，有多少种不同的二叉搜索树？

回顾一下二叉搜索树的定义：

**二叉查找树**(Binary Search Tree)是指一棵空树或者具有下列性质的[二叉树](https://zh.wikipedia.org/wiki/二叉树)：

1. 若任意节点的左子树不空，则左子树上所有节点的值均小于它的根节点的值；
2. 若任意节点的右子树不空，则右子树上所有节点的值均大于或等于它的根节点的值；
3. 任意节点的左、右子树也分别为二叉查找树；

由于二叉搜索树的性质，在1...n 中任取一个数作为根节点i都可以将左右两边的数分为左右子树。

而左右子树又是严格递增的，所以只需要计算左子树数量和右子树数量并将他们相乘，就能得到以i为节点不同的BST数量，记作**F[i]**

**F[n] = sum(F[i-1]*F[n-i])     i = [1,n]**


动态规划简化递归中的重复计算

讨论初始条件和最后1步

如果BST为空，则只有一种，F[0] = 0

如果BST有1个节点，也只有一种，F[1] = 1

```java
class Solution {
    public int numTrees(int n) {
        //F[n] = sum(F[n-i]*F[i-1]), i from 1 to n
        //F[1] = 1,F[0] = 1
        int[] dp = new int[n+1];
        dp[1] = 1;dp[0] = 1;
        for(int i = 2;i <= n;i ++)
        {
            int sum = 0;
            for(int j = 1;j <= i;j++)
            {
                sum += dp[i-j]*dp[j-1];
            }
            dp[i] = sum;
        }
        return dp[n];
    }
}
```

延伸：

<a href = "[https://baike.baidu.com/item/%E5%8D%A1%E7%89%B9%E5%85%B0%E6%95%B0](https://baike.baidu.com/item/卡特兰数)">卡特兰数</a>

