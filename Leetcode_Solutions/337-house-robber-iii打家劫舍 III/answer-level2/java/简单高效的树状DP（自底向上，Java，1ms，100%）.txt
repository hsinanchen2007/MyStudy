可以回顾一下初级版的[LeetCode198：打家劫舍](https://leetcode-cn.com/problems/house-robber/)，这是一道一维dp，状态转移方程也很简单：

```
dp[i] = Math.max(dp[i - 2] + nums[cur], dp[i - 1]);
```

当前偷窃的最大金额可能有两种来源情况，要么偷了这家，上一家没偷；要么偷了上一家，这家没偷。因此每一个结点的dp值和前两个结点的dp值有关。

这道升级版的树状动态规划问题也可以由一维的dp延伸来，只是情况稍微复杂一些，每一个节点的dp值与三层二叉树的结点dp值相关。对于下图所示的一棵三层满二叉树来说：

```
      1
    /   \
   2     3
  / \   / \ 
 4   5 6   7

```

在每个结点的金额非负的情况下，且要保证取值结点不相邻，只可能有四种最大的取值方式：

```
1. 结点2 + 结点3
2. 结点1 + 结点4 + 结点5 + 结点6 + 结点7
3. 结点2 + 结点6 + 结点7
4. 结点3 + 结点4 + 结点5
```

那么我们可以自底向上递归进行这个dp运算，令dp[i]代表以i结点为根节点的子树的最大偷窃金额值，计算结束后将dp值直接保存在i结点的val值当中返回。可以推出状态转移方程为：

```
dp[root] = Max(dp[l]+dp[r], root.val+dp[ll]+dp[lr]+dp[rr]+dp[rl], dp[l]+dp[rl]+dp[rr], dp[r]+dp[lr]+dp[ll]);
```

分别对应上述四种情况。而观察发现，在dp[l]和dp[r]的计算中实际已经包含了dp[ll]、dp[lr]、dp[rr]、dp[rl]的取舍情况，因此可以简化为前两种情况。状态转移方程简化为：

```
dp[root] = Max(dp[l]+dp[r], root.val+dp[ll]+dp[lr]+dp[rr]+dp[rl]);
```

为了方便运算，我们一般会为dp数组赋予初值。在树状dp中同样，我们需要将每一个非叶结点作为根节点的子树构造成一棵三层满二叉树方便运算。

对于叶子结点，我们给其添加值为0的左右子结点。

对于左/右子树为空的非叶节点，我们在其左/右添加一棵两层值为0的满二叉树。

```java
class Solution {
    public int rob(TreeNode root) {
        return Solution(root).val;
    }

    public TreeNode Solution(TreeNode root){
        if(root == null){
            TreeNode newNode = new TreeNode(0);
            return Solution(newNode);
        }
        if(root.left == null && root.right == null){
            root.left = new TreeNode(0);
            root.right = new TreeNode(0);
            return root;
        }

        root.left = Solution(root.left);
        root.right = Solution(root.right);
        root.val = Math.max(root.left.val + root.right.val, root.val + root.left.left.val + root.left.right.val + root.right.left.val + root.right.right.val);

        return root;
    }
}
```

---

欢迎大家与我交流：

github：[https://github.com/ChopinXBP/LeetCode-Babel](https://github.com/ChopinXBP/LeetCode-Babel)

博客：[LeetCode 从零单刷个人笔记整理（持续更新）](https://blog.csdn.net/qq_20304723/article/details/89401203)

