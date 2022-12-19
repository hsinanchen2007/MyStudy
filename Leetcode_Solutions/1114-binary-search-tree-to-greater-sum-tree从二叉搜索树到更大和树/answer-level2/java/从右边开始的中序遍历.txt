```
  public TreeNode bstToGst(TreeNode root) {
        dfs(root, 0);
        return root;
    }
    public int dfs (TreeNode root, int cur) {
        if(null == root){
            return cur;
        }
        int right = postOrderTreeNode(root.right, cur);
        root.val = right + root.val;
        cur = root.val;
        int left = postOrderTreeNode(root.left, cur);
        return left;
    }
```

