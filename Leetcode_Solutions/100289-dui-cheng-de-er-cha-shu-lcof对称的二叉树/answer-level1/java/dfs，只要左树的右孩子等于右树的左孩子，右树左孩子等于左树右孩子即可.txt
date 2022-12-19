### 解题思路
![屏幕快照 2020-02-12 20.53.19.png](https://pic.leetcode-cn.com/20a2db97c0667b694302dad687d832c066d0c80352f10c3e074911e55e788124-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202020-02-12%2020.53.19.png)


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
    public boolean isSymmetric(TreeNode root) {
        if (root == null) {
            return true;
        }
        return isSym(root.left, root.right);
    }

    private boolean isSym(TreeNode left, TreeNode right) {
        if (left == null && right == null) {
            return true;
        }
        if ((left == null && right != null) || (left != null && right == null) || left.val != right.val) {
            return false;
        }
        return isSym(left.right, right.left) && isSym(left.left, right.right);
    }
}
```