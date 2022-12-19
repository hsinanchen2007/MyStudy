### 解题思路
在计算高度的同时判断是否是平衡树，不是的话就返回Integer.MAX_VALUE,判断左右子树是否有MAX_VALUE可以判断是否这个树是不是平衡树。

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
        if (root == null) return true;
        int left = hight(root.left);
        int right = hight(root.right);
        if (left == Integer.MAX_VALUE || right == Integer.MAX_VALUE) return false;
        return Math.abs(left - right) > 1 ? false : true;
    }

    public int hight(TreeNode root) {
        if (root == null) return 0;
        if (root != null && root.left == null && root.right == null) {
            return 1;
        }
        int left = 0, right = 0;
        if (root.left != null) left = hight(root.left);
        if (root.right != null) right = hight(root.right);
        if (Math.abs(left - right) > 1 || left == Integer.MAX_VALUE || right == Integer.MAX_VALUE) return Integer.MAX_VALUE;
        return Math.max(left, right) + 1;
    }

}
```