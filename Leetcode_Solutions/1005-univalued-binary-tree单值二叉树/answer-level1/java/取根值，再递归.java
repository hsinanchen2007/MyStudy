```
    int v;
    public boolean isUnivalTree(TreeNode root) {
        v = root.val;
        return helper(root);
    }
    public boolean helper(TreeNode root) {
        if(root == null) {
            return true;
        }
        if(root.val != v) {
            return false;
        }
        return helper(root.left) && helper(root.right);
    }
```
