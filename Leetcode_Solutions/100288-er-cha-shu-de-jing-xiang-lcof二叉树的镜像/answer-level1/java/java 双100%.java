```
class Solution {
    public TreeNode mirrorTree(TreeNode root) {
        if(root == null) return null;
        if(root.left != null || root.right != null){
            TreeNode tmp = root.left;
            root.left = root.right;
            root.right = tmp;
        }
        if(root.left!= null) mirrorTree(root.left);
        if(root.right!=null) mirrorTree(root.right);
        return root;
    }
}
```
