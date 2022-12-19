### 解题思路
此题类似于求树最大深度，回想一下，树的深度怎么求？

递归返回左右子树高度较大的那个，然后+1。

这里基本类似，只是如果当前节点是left节点，就只能返回right子树"高度"（路径）。同样的，如果当前节点是right节点，那么只能返回left子树的"高度"（路径）。这个交错路径的最大值，就在求每个节点高度的过程中。

于是，我们采用DFS的深度优先搜索，来遍历二叉树，先左右，然后根的方式，来获取最大值。

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
    public int longestZigZag(TreeNode root) {
        int[] res = {0};
        nodeZigZag(res,root,false);
        return res[0];
    }

    /**
     * 递归求左右孩子
     * @param res
     * @param node
     * @param isLeft 当前node是否左孩子
     * @return
     */
    private int nodeZigZag(int[] res,TreeNode node,boolean isLeft){
        if (node == null){
            return 0;// 递归终止条件
        }
        // 左右子树锯齿情况
        int lCount = nodeZigZag(res,node.left,true);
        int rCount = nodeZigZag(res,node.right,false);
        int max = Math.max(lCount,rCount);
        // 三条路线的最大值
        res[0] = Math.max(res[0],max);
        // node为根节点的最大值
        // 当前节点是左孩子，走右边，否则走左边
        return 1 + (isLeft ? rCount : lCount);
    }
}
```