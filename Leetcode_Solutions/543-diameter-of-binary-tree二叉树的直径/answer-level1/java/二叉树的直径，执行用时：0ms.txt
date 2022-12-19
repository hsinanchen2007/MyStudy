### 解题思路
后序遍历二叉树，统计每个节点到叶子节点的节点个数之和，定义一个全局变量来存储最大节点个数，根据题意，二叉树的直径是统计分支数之和，所以需要-1。

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
    int max = Integer.MIN_VALUE;
    public int diameterOfBinaryTree(TreeNode root) {
        if(root == null || (root.left == null && root.right == null)) return 0;
        helper(root);
        return max - 1;
    }

    private int helper(TreeNode root) {
        if(root == null) return 0;
        int left = helper(root.left);
        int right = helper(root.right);
        if(left + right + 1 > max) max = left + right + 1;
        return left > right ? left + 1 : right + 1;
    }
}
```