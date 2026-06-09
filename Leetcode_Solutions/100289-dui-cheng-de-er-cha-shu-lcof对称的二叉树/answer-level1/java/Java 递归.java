```
 
    public boolean isSymmetric(TreeNode root) {
       if(null==root){
           return true;
       }
        return dfs(root.left,root.right);
    }

    private boolean dfs(TreeNode leftNode, TreeNode rightNode) {
        if (null != leftNode && null == rightNode) {
            return false;
        }
        if (null == leftNode && null != rightNode) {
            return false;
        }
        if (null != leftNode && null != rightNode && leftNode.val != rightNode.val) {
            return false;
        }
        if (null != leftNode && null != rightNode && !dfs(leftNode.left, rightNode.right)) {
            return false;
        }
        if (null != leftNode && null != rightNode && !dfs(leftNode.right, rightNode.left)) {
            return false;
        }
        return true;
    }
```
