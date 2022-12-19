任意两个节点之间的边数都可能是最大直径

最大的直径不一定包括根节点

这道题很容易有的误区就是：从根节点出发，找到左边数的最大深度 `leftDepth`，再找到右边树的最大深度 `rigthDepth`

然后 `return leftDepth+rigthDepth + 1`（如果二叉树的根节点深度为0的话）

![屏幕快照 2020-03-10 00.36.38.png](https://pic.leetcode-cn.com/c65424cbaecd2369fda4a45c43d911add3cfe86133cd02b10795dce91c6e149b-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202020-03-10%2000.36.38.png){:width=200}

从上面的图可以看出，情况并不是这样，因为最大值不一定要包含根节点。

## 解题思路
从上面的分析可知，最大值不一定包含根节点，但是一定是：经过一个节点，该节点左右子树的最大深度之和 $+1$（二叉树的根节点深度为 $0$）
于是，可以使用 DFS，找出所有节点的最大直径，在取出最大值 `res`;

定义一个全局变量 `res`，用来记录最大直径
使用 `dfs(root)` 遍历所有的节点，**`dfs(root)` 的作用是：找出以 `root` 为根节点的二叉树的最大深度**

将根节点的深度定义为 $1$（和上面分析的深度定义不一样）
`root` 为跟节点的最大深度为 `Math.max(leftDepth,rigthDepth) + 1`
`res` 取值为以经过 `root`，左右子树的最大深度之和 `leftDepth + rigthDepth`（不用加 $1$，是因为根节点的深度是 $1$）
通过递归，找到 `res` 的最大值

<![屏幕快照 2020-03-10 01.13.21.png](https://pic.leetcode-cn.com/f15403c27f83797a8c285542f93c6e4fe162bc9078c503688bf491f06f9c3e08-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202020-03-10%2001.13.21.png),![屏幕快照 2020-03-10 01.13.26.png](https://pic.leetcode-cn.com/767fafb0ab47aaaeedf1325d50f98bc9604b1927e41b9678708c92c3d701bb1d-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202020-03-10%2001.13.26.png),![屏幕快照 2020-03-10 01.13.32.png](https://pic.leetcode-cn.com/23db369c8fa182448c84e4d01edf5642722cca526e54fdf3b50badfb6212c609-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202020-03-10%2001.13.32.png),![屏幕快照 2020-03-10 01.13.37.png](https://pic.leetcode-cn.com/fb82a0163e1d7012f85156c0c9bbda51faf7b0d4f1bdbde3305bc442a2ea53fe-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202020-03-10%2001.13.37.png),![屏幕快照 2020-03-10 01.13.44.png](https://pic.leetcode-cn.com/586bf96b6af471ae80e4148b99d3cfada364828c88720d1897c9ae70a2baf2d6-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202020-03-10%2001.13.44.png)>

```java [-Java]
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
    int res = 0; 
    public int diameterOfBinaryTree(TreeNode root) {
        dfs(root);
        return res;
    }

    // 函数dfs的作用是：找到以root为根节点的二叉树的最大深度
    public int dfs(TreeNode root){
        if(root == null){
            return 0;
        }
        int leftDepth = dfs(root.left);
        int rigthDepth = dfs(root.right);
        res = Math.max(res,leftDepth + rigthDepth);
        return Math.max(leftDepth,rigthDepth) + 1;
    }
}
```