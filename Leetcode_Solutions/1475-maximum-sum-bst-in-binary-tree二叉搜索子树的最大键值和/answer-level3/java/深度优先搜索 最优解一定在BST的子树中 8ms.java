### 解题思路
由root开始的树，是一颗**二叉树**，题目要求**二叉搜索树**的最大键值和。显然，我们要先找到**二叉搜索树节点**。

如何判断一棵树是否BST呢？

**左右子树满足BST性质**，同时$max(root.left) < root.val < min(root.right)$。只要满足这个条件的，就是BST。

这里为什么不需要再判断root.left,root,root.right的大小了呢？

**因为左右子树已经是BST了**，自然他们就满足BST的性质，满足$left.val < max(left)，right.val > min(right)$，所以，我们只要比较左子树最小，右子树最大和root节点的大小关系即可。 

由于二叉搜索树的左右子树也是二叉搜索树。那么，只要找到**每条路径最上层的二叉树搜索树节点**，然后以这些BST节点为根，对其节点值求和，就能得到所有的BST节点和的结果集。

每个BST的节点和，都满足$sum(node) = node.val + sum(node.left) + sum(node.right)$，那么在获取当前节点和的时候，必然已经知道了子节点的节点之和。故，最大值必然在求解的过程中。

递归进入左右子树的值没有返回的必要，因为最终结果都存在res[]中，局部结果集，不需要递归给上层。

![QQ图片20200330130657.png](https://pic.leetcode-cn.com/ea2d177fd319092e3b45e1c76bc31c1aa614b167070d8fff9fe52a74413b8002-QQ%E5%9B%BE%E7%89%8720200330130657.png)


画外音：部分小伙伴可能会疑惑，为什么我没有用全局变量在存储值，反而用一个局部数组来呢？因为`鲁迅先生说过：以局部变量为荣，以全局变量为耻。`

![9150e4e5ly1flvtk73zzuj20cc07m3yl.jpg](https://pic.leetcode-cn.com/649408b33709a82cdffb44945258ce3b3bb3e0a603d91b5ac322ef4a8354bc7d-9150e4e5ly1flvtk73zzuj20cc07m3yl.jpg)


在工业开发过程中，全局变量能避免，最好避免。为什么呢？全局变量（或者说成员变量），在这个类里是共享的。如果这个类有两个指针指向它，就会出现成员变量被修改的安全问题。比较常见的就是单例模式。（当然了，如果这个成员变量，只读不写，那是不会有线程安全问题的）

比如说线程1的一个指针把成员变量p的值设置成了x，那么自然，我希望下一次取这个成员变量p的时候它的值依然是x。可是如果线程2指针也来操作这个成员变量p，把他的值设置成了y。那么在这时候线程1来获取p的值的时候，就会拿到y的值，这就和预期的x不一样了，这个就是安全问题。

### 代码

```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    
    public int maxSumBST(TreeNode root) {
        int[] res = {0};
        maxSumBST(res, root);
        return res[0];
    }

    /**
     * 判断root为根节点的树是否是二叉搜索树
     *
     * @param root root节点
     * @param min  最小值
     * @param max  最大值
     * @return 是否是二叉搜索树
     */
    private boolean isBST(TreeNode root, int min, int max) {
        if (root == null) {
            return true;
        }
        return min < root.val && root.val < max && isBST(root.left, min, root.val) && isBST(root.right, root.val, max);
    }
    
    /**
     * 求节点和的最大值
     *
     * @param res res
     * @param node node
     * @return 较大节点和
     */
    private void maxSumBST(int[] res, TreeNode node) {
        // 这个节点是BST，直接求和了
        if (isBST(node, Integer.MIN_VALUE, Integer.MAX_VALUE)) {
            // 是二叉搜索树，求节点和，节点和的最优解，肯定在子节点求和的过程中
            sumNodeValue(res, node);
            return;
        }
        // 不是BST，递归进入左右子树
        maxSumBST(res, node.left);
        maxSumBST(res, node.right);
    }

    /**
     * 以node为root的节点求和
     *
     * @param res  结果集
     * @param node node
     * @return 节点之和
     */
    private int sumNodeValue(int[] res, TreeNode node) {
        if (node == null) {
            return 0;
        }
        // 二叉搜索树节点和的最大值，一定在子节点中会出现
        int sum = node.val + sumNodeValue(res, node.left) + sumNodeValue(res, node.right);
        // 这里记录结果的最大值
        res[0] = Math.max(res[0], sum);
        return sum;
    }
}
```