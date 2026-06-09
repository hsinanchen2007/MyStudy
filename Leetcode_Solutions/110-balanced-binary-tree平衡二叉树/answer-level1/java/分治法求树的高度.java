采用分治法思想求左右子树的高度，判断子数是否满足平衡二叉树。
```java
class Solution {
    private  boolean flag = true;
    public boolean isBalanced(TreeNode root) {
        high(root);
        return flag;  
    }
    private int high(TreeNode root){
        if(root==null) return 0;
        int leftHigh = high(root.left);
        int rightHigh = high(root.right) ;
        if(Math.abs(leftHigh-rightHigh)>1) flag = false;
        return Math.max(leftHigh,rightHigh)+1;
    }
}
```