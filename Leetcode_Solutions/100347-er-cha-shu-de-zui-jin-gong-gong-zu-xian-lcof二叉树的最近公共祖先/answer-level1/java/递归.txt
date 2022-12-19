### 解题思路
思路很简单：有三种情况
1.一左一右
2.两左
3.两右
第一种情况的话，root是最深的公共结点(最近公共祖先)
第二三两种情况的话，第一个碰见的p/q就是最深的公共结点(最近公共祖先)
执行用时 :8 ms, 在所有 Java 提交中击败了96.34%的用户
内存消耗 :41.9 MB, 在所有 Java 提交中击败了100.00%的用户

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
        if (root == null) return null;
        if (root.val == p.val || root.val == q.val) return root;
        TreeNode left = lowestCommonAncestor(root.left, p, q);
        TreeNode right = lowestCommonAncestor(root.right, p, q);
        if (left != null && right != null) return root;
        if (left != null) return left;
        if (right != null) return right;
        return null;
    }
}
```