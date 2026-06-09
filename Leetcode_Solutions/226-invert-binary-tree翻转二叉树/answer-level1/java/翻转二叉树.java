# 代码
```java []
class Solution {
    public TreeNode dfs(TreeNode root){
        if(root==null) return null;
        TreeNode left=dfs(root.left); 
        TreeNode right=dfs(root.right); 
        TreeNode tmp=left;
        root.left=right;
        root.right=tmp;
        return root;
    }
    public TreeNode invertTree(TreeNode root) {
        return dfs(root);
    }
}
```
