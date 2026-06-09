```
class Solution {
    public TreeNode invertTree(TreeNode root) {
        if(root == null) return null;
        TreeNode x = root.right;
        root.right = invertTree(root.left);
        root.left = invertTree(x);
        return root;
    }
}
```
