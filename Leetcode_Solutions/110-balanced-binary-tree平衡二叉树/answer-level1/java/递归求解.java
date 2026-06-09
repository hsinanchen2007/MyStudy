### 解题思路
递归求高度
递归判断是否满足条件

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
    public boolean isBalanced(TreeNode root) {
        if (root == null) {
            return true;
        }
        int leftTreeHeight = height(root.left);
        int rightTreeHeight = height(root.right);
        if (Math.abs(leftTreeHeight - rightTreeHeight) > 1) {
            return false;
        }
        boolean left = isBalanced(root.left);
        return left ? isBalanced(root.right) : left;
    }

    
    public int height(TreeNode root) {
        if (root == null) {
            return 0;
        }
        return Math.max(height(root.left), height(root.right)) + 1;
    }
}
```