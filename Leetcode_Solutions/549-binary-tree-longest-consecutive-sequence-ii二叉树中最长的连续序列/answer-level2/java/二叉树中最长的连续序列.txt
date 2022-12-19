## 解法

#### 方法 1：暴力 [Time Limit Exceeded]

我们容易知道一棵树中从一个点到另一个点只有唯一的一条路径。所以可能的路径书目录只有 ${{N}\choose{2}}$ 条，其中 $N$ 是节点的数目。

这个题的暴力解法是找到任意两点之间的路径，并检查这个路径是否是递增的或者递减的。通过这种方法我们可以找到最长上升或者下降序列。

**复杂度分析**

* 时间复杂度： $O(n^3)$。可能的路径数总共有 $n^2$ 条，检查每一条路径还需要 $O(n)$ 的时间。

* 空间复杂度： $O(n^3)$。总共有 $n^2$ 条路径，每条路径有 $O(n)$ 级别个节点。

#### 方法 2：一次遍历 [Accepted]

**算法**

这个解法很简单。在每一个点，我们使用两个变量 $inr$ 和 $dcr$，其中 $inr$ 表示当前点为止最长增长序列的长度（包括该点自己），$dcr$ 表示当前点为止最长下降序列的长度（包括该点自己）。

我们使用回溯函数 `longestPath(node)`，它的函数返回值为 $[inr, dcr]$ 这样的形式。我们将 $inr$ 和 $dcr$ 在当前点都初始化为 $1$。这是因为一个点自身总能形成一个长度为 $1$ 的连续上升和下降序列。

然后，我们可以通过调用 `longestPath(root.left)` 得到左孩子为终点的最长上升或者下降序列。如果左孩子的值比当前值小，那么左孩子与当前节点形成了一个下降序列。因此，当前节点的 $dcr$ 值为$right\_child(dcr)+1$。而如果左孩子的值比当前点的值打，左孩子与当前节点形成一个上升序列，所以我们更新当前点的 $inr$ 值为 $left\_child(inr) + 1$。

然后，我们对于右孩子也做同样的过程。我们通过取左右孩子对应值的较大值得到当前节点 $inr$ 和 $dcr$ 的值。

接下来，在我们得到每个点的 $inr$ 和 $dcr$ 的值以后，我们更新当前找到的最长连续路径的长度，$maxval =  \text{max}(inr + dcr - 1)$。

下面的动图更好地说明了这一过程。

<![image.png](https://pic.leetcode-cn.com/3b70716a6c57f732e67683181cbc8125aa0a00ed1917148a3eda43ec369b208b-image.png),![image.png](https://pic.leetcode-cn.com/9fbb6cfe1c9d3ad294cf3f619c3778173c9ddbcb8b099582c99ed53a24dce104-image.png),![image.png](https://pic.leetcode-cn.com/18ed5529e346961dccd35b729c6891d5f6148e91c023e7d83f872c1e1036c9e0-image.png),![image.png](https://pic.leetcode-cn.com/503cf5b8969b6f9656a8c1cd9694ab4cef214e91df1b73997cbd838898a899bc-image.png),![image.png](https://pic.leetcode-cn.com/0fb82d4e335695059566bea411fc4eff99f4a890b15db0093b0f899e4a310a12-image.png),![image.png](https://pic.leetcode-cn.com/e435aa95fc39897ab19aa9c73e68c6680b6ee530e1f4ae2e5380af8236a45f50-image.png),![image.png](https://pic.leetcode-cn.com/0c9784e3460a50d5cf145f0cfa50db5ad98ea221f739c5cc97b83922c82aa1f4-image.png),![image.png](https://pic.leetcode-cn.com/fe62d9d99bd912c72837ffcb24297be14826a482b6ed01af21519f0426624515-image.png),![image.png](https://pic.leetcode-cn.com/fa3467b8eb157b85485f464c8f3da8cd92802331b88564d92da4d79e4834d9a5-image.png),![image.png](https://pic.leetcode-cn.com/271b8f290d24c65f37f6a41269d3ab40c0c8cd7a78f69150e760c9f533f1e1a3-image.png),![image.png](https://pic.leetcode-cn.com/8dd04727a28d8a0b9dfe0a53f397585afcc6dfb251d7f6479d9f92b70aec889c-image.png),![image.png](https://pic.leetcode-cn.com/5d3c0b3bc83dfc9e4e8adcc3b96eec84c27a851fd8409b32def0914f6c5e4f12-image.png),![image.png](https://pic.leetcode-cn.com/3fdc4fb3292063d0cf2eaeeff7f4b15c65ef034faf8f8d3ff910aa468f268901-image.png),![image.png](https://pic.leetcode-cn.com/0fe36c43ec1dd6bd17d8231c4723597bc775c7202ffc4f79b21d299851fff459-image.png),![image.png](https://pic.leetcode-cn.com/44e124619dd4b4f0f3297443bc6831bdad41923c7f5da01df5bdffb36b71edd9-image.png),![image.png](https://pic.leetcode-cn.com/3b2205ec4ef9d62872829a926fd275c69ce2a7761aa6e83093b3649863b8ff75-image.png)>

```Java []
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    int maxval = 0;
    public int longestConsecutive(TreeNode root) {
        longestPath(root);
        return maxval;
    }
    public int[] longestPath(TreeNode root) {
        if (root == null)
            return new int[] {0,0};
        int inr = 1, dcr = 1;
        if (root.left != null) {
            int[] l = longestPath(root.left);
            if (root.val == root.left.val + 1)
                dcr = l[1] + 1;
            else if (root.val == root.left.val - 1)
                inr = l[0] + 1;
        }
        if (root.right != null) {
            int[] r = longestPath(root.right);
            if (root.val == root.right.val + 1)
                dcr = Math.max(dcr, r[1] + 1);
            else if (root.val == root.right.val - 1)
                inr = Math.max(inr, r[0] + 1);
        }
        maxval = Math.max(maxval, dcr + inr - 1);
        return new int[] {inr, dcr};
    }
}
```

**复杂度分析**

* 时间复杂度： $O(n)$。整棵树会被遍历一遍。
* 空间复杂度： $O(n)$。最坏情况下低估深度为 $n$。

该解法由 [@vinod23](https://leetcode.com/vinod23) 提供。
