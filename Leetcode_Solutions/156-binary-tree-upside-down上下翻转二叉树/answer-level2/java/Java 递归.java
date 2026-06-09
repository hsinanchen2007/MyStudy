```
class Solution {
    public TreeNode upsideDownBinaryTree(TreeNode root) {
        return helper(null, root);
    }
    public TreeNode helper(TreeNode parent, TreeNode node) {
        if(node == null)
            return parent;
        TreeNode ret = helper(node, node.left);
        if(parent != null)
            node.left = parent.right;
        else 
            node.left = null;
        node.right = parent;
        return ret;
    }
}
```