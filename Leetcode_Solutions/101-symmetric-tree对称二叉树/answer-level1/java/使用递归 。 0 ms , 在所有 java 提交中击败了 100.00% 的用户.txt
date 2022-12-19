```
class Solution {
   public boolean isSymmetric(TreeNode root) {
        if (root == null) 
            return true;
        //使用递归判断左右节点，空，值，是否相等，在递归往下掉。
        return isSymmetric(root.left, root.right);
    }

    boolean isSymmetric(TreeNode left, TreeNode right) {
        if (left == null && right == null) return true;
        if (left == null || right == null)  return false;
        if (left.val != right.val)  return false;
        return isSymmetric(left.left, right.right) && isSymmetric(left.right, right.left);
    }
}
```