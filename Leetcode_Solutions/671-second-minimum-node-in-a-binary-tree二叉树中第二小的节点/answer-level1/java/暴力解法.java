class Solution {
    public int findSecondMinimumValue(TreeNode root) {
        ArrayList<Integer> arr = new ArrayList<>();
        add(root,arr);
        Collections.sort(arr);
        if(arr.size()==1)
            return -1;
        int num = arr.get(0);
        boolean flag = false;
        for(int i = 1; i < arr.size(); i++){
            if(num != arr.get(i)){
                num = arr.get(i);
                flag = true;
                break;
            }
        }
        if(!flag)
            return -1;
        return num;
    }
    
    public void add(TreeNode root, ArrayList<Integer> arr){
        if(root == null)
            return ;
        add(root.left,arr);
        arr.add(root.val);
        add(root.right,arr);
    }
}