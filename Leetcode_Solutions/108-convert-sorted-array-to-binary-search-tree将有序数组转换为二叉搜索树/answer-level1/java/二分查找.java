```
class Solution {
    public TreeNode sortedArrayToBST(int[] nums) {
        if(nums.length==0) return null;
        return balance(nums,0,nums.length-1);
    }
    public TreeNode balance(int[] nums,int lower,int high){
        if(lower<=high && lower>=0 && high<nums.length ){
        int mid=(lower+high)/2;
        TreeNode root=new TreeNode(nums[mid]);
        root.right=balance(nums,mid+1,high);
        root.left=balance(nums,lower,mid-1);
        return root;
        }
        return null;
    }
}
```
