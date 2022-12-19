简洁return语句
```
public boolean isSymmetric(TreeNode root) {
    if(root == null) return true;
    return recursive(root.left,root.right);
}

private boolean recursive(TreeNode left,TreeNode right){
    if(right == null && left == null) return true;
    return right!= null && left != null && left.val == right.val &&
            recursive(left.left,right.right) && recursive(left.right,right.left);
}
```
