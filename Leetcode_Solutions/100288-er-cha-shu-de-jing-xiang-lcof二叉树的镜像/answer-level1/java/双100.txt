```
class Solution {
    public TreeNode mirrorTree(TreeNode root) {
        if(root==null)
            return null;
        mirrorTree(root.left);
        mirrorTree(root.right);
        TreeNode left=root.left;
        root.left=root.right;
        root.right=left;
        return root;
    }
}
```
