class Solution {
    public boolean checkSubTree(TreeNode t1, TreeNode t2) {
        if(t1==null&&t2==null)return true;
        if(t1==null||t2==null)return false;
        if(t1.val==t2.val){
            if(check(t1,t2))return true;
        }
        return checkSubTree(t1.left, t2)||checkSubTree(t1.right,t2);
        
    }
    public boolean check(TreeNode t1, TreeNode t2){
        if(t1==null&&t2==null)return true;
        if(t1==null||t2==null)return false;
        if(t1.val == t2.val){
            return check(t1.left,t2.left)&&check(t1.right,t2.right);
        }else{
            return false;
        }
    }
}