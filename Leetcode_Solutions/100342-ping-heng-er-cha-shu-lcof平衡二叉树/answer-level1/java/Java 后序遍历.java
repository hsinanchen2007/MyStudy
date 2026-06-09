```
class Solution {
  private boolean flag=true;
    public boolean isBalanced(TreeNode root) {
        if(root==null) return true;
        height(root);
        if(flag) return true;
        return false;
    }
    private int height(TreeNode root)
    {
        if(root==null) return 0;
        int left = height(root.left);
        int right = height(root.right);
        if(Math.abs(left-right)>1) flag=false;
        return Math.max(left,right)+1;
    }
}
```
