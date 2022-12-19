```
class Solution {
    public boolean twoSumBSTs(TreeNode root1, TreeNode root2, int target) {
        if(root1==null){
            return false;
        }
        if(vist(root1,root2,target)){
            return true;
        }
        if(twoSumBSTs(root1.left, root2,target))
            return true;
        if(twoSumBSTs( root1.right, root2,target))
            return true;
        return false;
    }

    public boolean vist(TreeNode root1, TreeNode root2, int target){
        if(root1==null || root2 == null){
            return false;
        }
        int target2 = target - root1.val;
        //find target2 int tree2
        if(find(root2,target2)){
            return true;
        }else{
            return false;
        }  
    }
    
    public boolean find(TreeNode root2, int target){
        if(root2==null){
            return false;
        }
        if(root2.val>target){
             return find(root2.left,target);
        }
        else if(root2.val<target)
        {
             return find(root2.right,target);
        }else
        {
            return true;
        }
    }
}
```
