### 解题思路
![屏幕快照 2020-03-01 10.49.26.png](https://pic.leetcode-cn.com/ad16f31bc66cd1d9f0951c0ced608f3cf54aaed573e40a9ad7907bdf31fb145d-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202020-03-01%2010.49.26.png)


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
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        if (root == null) {
            return null;
        }
        if (root.val == p.val || root.val == q.val) {
            return root;
        }
        TreeNode left = lowestCommonAncestor(root.left, p, q);
        TreeNode right = lowestCommonAncestor(root.right, p, q);
        if (left != null && right != null) {
            return root;
        }
        if (left != null) {
            return left;
        }
        if (right != null) {
            return right;
        }
        return null;
    }
}
```