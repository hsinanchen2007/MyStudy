### 解题思路
如果某二叉树中任意节点的左右子树的深度相差不超过1，那么它就是一棵平衡二叉树。
根据此提示判断就可以
![捕获.PNG](https://pic.leetcode-cn.com/d68ec409956876e3e6bfdb6aed2a390efb340d281473836aa3ff55b75cb20a06-%E6%8D%95%E8%8E%B7.PNG)


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
   boolean isBalanced;
    public boolean isBalanced(TreeNode root) {
        isBalanced = true;
        dfs(root);
        return isBalanced;
    }

    public int dfs(TreeNode node) {
        if (node == null) {
            return 0;
        }
        int leftDepth = dfs(node.left); //左子树深度。
        int rightDepth = dfs(node.right); //右子树深度。
        if (leftDepth == -1 || rightDepth == -1) { //已经确定不是平衡二叉树，跳过。
            return -1;
        }
        if (Math.abs(leftDepth - rightDepth) > 1) { //左右子树的深度相差超过1，说明不是平衡二叉树。
            isBalanced = false;
            return -1;
        }
        return 1 + Math.max(leftDepth, rightDepth); //返回深度。
    }

}
```