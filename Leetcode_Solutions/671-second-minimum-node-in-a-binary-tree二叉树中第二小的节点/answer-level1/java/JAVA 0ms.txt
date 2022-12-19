用一个信号量来判断是继续往前找，还是找更小且不与头结点重合的值


class Solution {
    int min;
    int head;
    boolean isChange=false;
    public int findSecondMinimumValue(TreeNode root) {
        min=root.val;
        head=root.val;
        helper(root);
        return isChange?min:-1;
    }
    public void helper(TreeNode root){
        if(root==null) return;
        if(root.val>min&&!isChange) {min=root.val;isChange=true;}
        if(root.val<min&&isChange&&root.val!=head){min=root.val;}
        helper(root.left);
        helper(root.right);
    }
}