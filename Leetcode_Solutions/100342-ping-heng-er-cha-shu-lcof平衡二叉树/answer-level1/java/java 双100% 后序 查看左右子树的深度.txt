```
class Solution {
    public boolean isBalanced(TreeNode root) {
        return deep(root) != -1;
    }

    int deep(TreeNode root){
        if(root == null) return 0;
        int left = deep(root.left);
        int right = deep(root.right);
        if(left == -1 || right == -1) return -1;
        return Math.abs(left-right)>1?-1:Math.max(left,right)+1;
    }
}
```
