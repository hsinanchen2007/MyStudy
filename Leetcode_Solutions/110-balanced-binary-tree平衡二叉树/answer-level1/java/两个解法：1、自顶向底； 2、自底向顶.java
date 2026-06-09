```
1、自顶向下
class Solution {
    public boolean isBalanced(TreeNode root) {
        if(null == root) {
            return true;
        }
        if(isBalanced(root.left) && isBalanced(root.right) && Math.abs(height(root.left)-height(root.right))<=1) {
            return true;

        }
         return false;
    }
    public int height(TreeNode root) {
        if(null == root) {
            return 0;
        }
        return 1+ Math.max(height(root.left), height(root.right));
    }
}

2、自底向顶:提前阻断
class Solution {
    public boolean isBalanced(TreeNode root) {
         return height(root) != -1;
    }
    public int height(TreeNode root) {
        if(null == root) {
            return 0;
        }
        int left = height(root.left);
        if(left == -1) {
            return -1;
        }
        int right = height(root.right);
        if(right == -1) {
            return -1;
        }
        return Math.abs(left-right)<=1? 1+Math.max(left, right):-1;
    }
}
```
