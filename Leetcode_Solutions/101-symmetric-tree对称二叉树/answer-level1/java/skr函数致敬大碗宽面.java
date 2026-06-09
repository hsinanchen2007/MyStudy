```
class Solution {
    public boolean isSymmetric(TreeNode root) {
       
        if(root==null){
            return true; 
        }else {
            return skr(root.left,root.right);
        }
    }
        
        
       public  boolean skr(TreeNode a, TreeNode b){
            if (a!=null&&b!=null){
                return a.val ==b.val&&skr(a.left,b.right)&&skr(a.right,b.left);
                
            }
            if((a==null&&b!=null)||(a!=null&&b==null)){
return false;
            }
          return true;
        }
    }
