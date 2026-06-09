时间100%
```
class Solution {
    private boolean ret = true;
    public boolean isBalanced(TreeNode root) {
        getDeep(root);
        return ret;
    }
    private int getDeep(TreeNode root){
        if(root==null)return 0;
        int deep = 1;
        int left = getDeep(root.left);
        int right = getDeep(root.right);
        deep += (left>right)?left:right;

        //加这句

        if(Math.abs(left-right)>1)ret=false;



        return deep;
    }
}
```