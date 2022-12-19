### 解题思路
动态规划

首先，最先需要注意的题目重点之一：二叉搜索树。
这个条件代表什么呢？直观上看，所有小于当前节点的数字都在左子树，所有大于当前节点的数字都在右子树。对这个题目的价值：假设我选择了一个数字作为根节点，那么小于这个数字的所有数字都在左子树，大于这个数字的所有数字都在右子树，这不就是递归方程吗？

递归方程就是  f(i,j) = 聚合(f(i,k) + f(k,j))，k=i,i+1...j
递归方法参考官网解题思路。

递归过程中有重复求解，这些可以通过缓存中间结果来进行剪枝。

另外，我喜欢迭代，不喜欢递归。
迭代需要考虑两点，迭代起点和迭代的前进方向。比较容易想到的是，当i=j的时候，f(i,j)就一个结果，是包含一个节点的树
一般来说，我们的前进方向可能是i从1到n， j也从1到n。但是从递归方程可以看到，这种方法是不可行的，因为当计算f(i,j)的时候，用到的f(k,j)可能还并没有进行计算。那怎么办呢？需要找一种方法，使得计算f(i,j)的时候，f(i,k) 和 f(k,j)都已经计算过了。我们可以发现f(i,k) 和 f(k,j)的长度都是小于等于f(i,j)的，所以将前进方向选择为长度从1到n扩展，是一个可行方案。代码如下：

### 代码

```java
class Solution {
    public List<TreeNode> generateTrees(int n) {
        if (n == 0) return new ArrayList<>();
        ArrayList<TreeNode>[][] dp = new ArrayList[n + 1][n + 1];
        for (int i = 1; i <= n; i++) {
            TreeNode treeNode = new TreeNode(i);
            ArrayList<TreeNode> list = new ArrayList<>();
            list.add(treeNode);
            dp[i][i] = list;
        }

        ArrayList<TreeNode> listWithNull = new ArrayList<>();
        listWithNull.add(null);
        for (int len = 2; len <= n; len++) {
            for (int start = 1, end = start + len - 1; end <= n; start++, end++) {
                ArrayList<TreeNode> currentList = new ArrayList<>();
                for (int k = start; k <= end; k++) {
                    List<TreeNode> leftList = start == k ? listWithNull : dp[start][k - 1];
                    List<TreeNode> rightList = end == k ? listWithNull : dp[k + 1][end];
                    for (TreeNode leftNode : leftList) {
                        for (TreeNode rightNode : rightList) {
                            TreeNode current = new TreeNode(k);
                            current.left = leftNode;
                            current.right = rightNode;
                            currentList.add(current);
                        }
                    }
                }
                dp[start][end] = currentList;
            }
        }
        return dp[1][n];
    }
}
```