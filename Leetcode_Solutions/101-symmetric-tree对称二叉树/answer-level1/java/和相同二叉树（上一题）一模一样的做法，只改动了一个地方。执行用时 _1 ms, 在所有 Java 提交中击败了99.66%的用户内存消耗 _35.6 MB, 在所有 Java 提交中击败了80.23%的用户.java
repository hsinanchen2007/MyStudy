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
/*
    执行用时 :1 ms, 在所有 Java 提交中击败了99.66%的用户内存消耗 :35.6 MB, 在所有 Java 提交中击败了80.23%的用户
*/
class Solution {
    public boolean isSymmetric(TreeNode root) {
        return isSameTree(root,root);
    }
    private boolean isSameTree(TreeNode p, TreeNode q) {
        if(p == null && q == null) return true;
        if(p == null && q != null) return false;
        if(p != null && q == null) return false;
        if(p.val == q.val) {
            return isSameTree(p.left,q.right) && isSameTree(p.right,q.left);
        }
        return false;
    }
}
```
