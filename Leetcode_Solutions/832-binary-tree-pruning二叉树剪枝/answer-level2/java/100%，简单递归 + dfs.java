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
    public TreeNode pruneTree(TreeNode root) {
        if(h(root))
            return root;
        return null;
    }

    private boolean h(TreeNode rt) {
        if(rt == null)
            return false;
        boolean r = h(rt.right);
        boolean l = h(rt.left);
        if(!r)
            rt.right = null;
        if(!l)
            rt.left = null;
        return rt.val == 1 || r || l;
    }
}
```
