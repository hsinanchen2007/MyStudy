### 解题思路

深度遍历 

注意：二叉树的最大直径 

可能会有某个子树的直径大于整个二叉树的直径，
所以不能直接遍历整个二叉树，而要把所有子树求出来的直径对比，找出最大的那一个,比如[1,2,3,4,5, null, null, 6, null, null, 7]这种情况的最大值是4，不是3.

![二叉树最大直径.png](https://pic.leetcode-cn.com/f52ce0a210ae664260fcdce61231e53ef592ae0444ccac997ccb4d7c2e8bd0c7-%E4%BA%8C%E5%8F%89%E6%A0%91%E6%9C%80%E5%A4%A7%E7%9B%B4%E5%BE%84.png)


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
    private int max;  // 二叉树的最大直径 可能会有某个子树的直径大于整个二叉树的直径，
    // 所以不能直接遍历整个二叉树，而要把所有子树求出来的直径对比，找出最大的那一个,比如[1,2,3,4,5, null, null, 6, null, null, 7]这种情况的最大值是4，不是3
    public int diameterOfBinaryTree(TreeNode root) {
        if (root == null) return 0;
        max = 0;
        dfs(root);
        return max;
    }

    private int dfs(TreeNode root) {
        if (root != null) {
            int left = dfs(root.left);
            int right = dfs(root.right);
            max = Math.max(max, left + right);
            return Math.max(left, right) + 1;
        }
        return 0;
    }
}
```