
```java
class Solution {
    public TreeNode sortedArrayToBST(int[] nums) {
        int length =nums.length;
        if(length==0) return null;
        return sortedArrayToBST(nums,0,length-1);
    }
    
    private TreeNode sortedArrayToBST(int[] nums, int start, int end){
        if(start>end) return null;
        if(start==end) return new TreeNode(nums[start]);
        int cut = (end+start)>>>1;
        TreeNode root = new TreeNode(nums[cut]);
        root.left = sortedArrayToBST(nums,start,cut-1);
        root.right = sortedArrayToBST(nums,cut+1,end);
        return root;
    }
}
```