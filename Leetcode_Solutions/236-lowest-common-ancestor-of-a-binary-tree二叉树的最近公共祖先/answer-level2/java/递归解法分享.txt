```
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
        // 如果以rootroot为根的子树中包含p和q，则返回它们的最近公共祖先
        // 如果只包含p,则返回p
        // 如果只包含q,则返回q
        // 如果都不包含，则返回null
        if (root == null || root == p || root == q) return root;

        TreeNode left = lowestCommonAncestor(root.left,p,q);
        TreeNode right = lowestCommonAncestor(root.right,p,q);

        if (left == null) return right;
        if (right == null) return left;
        return root;
    }
}
```


执行用时 :8 ms, 在所有 Java 提交中击败了99.86% 的用户
内存消耗 :35.5 MB, 在所有 Java 提交中击败了81.83%的用户
