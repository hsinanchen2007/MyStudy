class Solution {
    public boolean isUnivalTree(TreeNode root) {
        ArrayList<Integer> arr = new ArrayList<>();
        UnivalTree(root,arr);
        boolean flag = true;
        for(int i = 1; i < arr.size(); i++){
            if(root.val!=arr.get(i)){
                flag = false;
            }
            if(flag == false)
                break;
        }
        return flag;
        
        
    }
    
    public void UnivalTree(TreeNode root,ArrayList<Integer> arr){
        if(root==null)
            return ;
        
        arr.add(root.val);
        if(root.left!=null)
            UnivalTree(root.left,arr);
        if(root.right!=null)
            UnivalTree(root.right,arr);
        
    }
}