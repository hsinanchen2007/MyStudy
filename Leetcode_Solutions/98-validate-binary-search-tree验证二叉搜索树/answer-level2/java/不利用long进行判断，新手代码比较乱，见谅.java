主要是进行Integer.MAX_VALUE和Integer.MIN_VALUE值得判断，利用minflag,maxflag作为标志 
class Solution {
    public boolean isValidBST(TreeNode root) {
        if(root==null) return true;
        return judgeTree(root,Integer.MAX_VALUE,Integer.MIN_VALUE,0,0);
    }
    public boolean judgeTree(TreeNode root,int maxValue,int minValue,int minflag,int maxflag){
        if(root==null)return true;
        if(root.val==Integer.MAX_VALUE){
            if(root.val>maxValue||root.val<minValue)return false;
            if(maxflag==0)
            return judgeTree(root.left,root.val,minValue,minflag,1)&&judgeTree(root.right,maxValue,root.val,minflag,1);
            return false;
        }
        if(root.val==Integer.MIN_VALUE){
            if(root.val>maxValue||root.val<minValue)return false;
            if(minflag==0)
            return judgeTree(root.left,root.val,minValue,1,maxflag)&&judgeTree(root.right,maxValue,root.val,1,maxflag);
            return false;
        }
        if(root.val<maxValue&&root.val>minValue){
            return judgeTree(root.left,root.val,minValue,minflag,maxflag)&&judgeTree(root.right,maxValue,root.val,minflag,maxflag);
        }
        return false;
    }
}