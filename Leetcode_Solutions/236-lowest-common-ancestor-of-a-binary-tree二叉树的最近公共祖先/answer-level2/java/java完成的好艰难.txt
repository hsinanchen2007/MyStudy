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
    public TreeNode ansiNode = null;
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        if(root==null) return root;
        isContain(root,p,q);
        return ansiNode;
    }

    public boolean isContain(TreeNode root,TreeNode p,TreeNode q){
        if(root == null) return false;

        boolean left = isContain(root.left,p,q);
        boolean right = isContain(root.right,p,q);
        boolean mid = root==p || root==q;
        if(mid&&left){
            ansiNode = root;
            return true;
        }
        if(mid&right){
            ansiNode = root;
            return true;
        }
        if(left&right){
            ansiNode = root;
            return true;
        }
        return left||right||mid;
    }
}
```
