```
 public int sumOfLeftLeaves(TreeNode root) {
        if(root==null){
            return 0;
        }
        int res=0;
        if(root.left!=null&&root.left.left==null&&root.left.right==null){
            res+= root.left.val;
        }
        return res+sumOfLeftLeaves(root.left)+sumOfLeftLeaves(root.right);
    }
```
