### 解题思路
![屏幕快照 2020-02-29 15.53.17.png](https://pic.leetcode-cn.com/5783b35c4bd45354b6e4c06ab73e225e2a3e048f2bbcfd13614eb3ac4ce7ae44-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202020-02-29%2015.53.17.png)


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
        if (Math.abs(maxDepth(root.left) - maxDepth(root.right)) > 1) {
            return false;
        }
        return isBalanced(root.left) && isBalanced(root.right);
    }

    private int maxDepth(TreeNode node) {
        if (node == null) {
            return 0;
        }
        return Math.max(maxDepth(node.left), maxDepth(node.right)) + 1;
    }
}
```