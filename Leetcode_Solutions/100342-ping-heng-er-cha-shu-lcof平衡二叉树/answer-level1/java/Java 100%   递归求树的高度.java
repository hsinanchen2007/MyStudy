### 解题思路
递归求树的高度，当出现左右子树高度差值大于1，则表示不是平衡的。
需要设置全局变量，默认值为true。

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
    boolean flag = true;
    public boolean isBalanced(TreeNode root) {
        if (root == null) {
            return true;
        }

        high(root);
        return flag;
    }

    private int high(TreeNode root) {
        if (root == null) {
            return 0;
        }

        int left = high(root.left);
        int right = high(root.right);
        if (Math.abs(left - right) > 1) {
            flag = false;
        }

        return Math.max(left, right) + 1;
    }
}
```