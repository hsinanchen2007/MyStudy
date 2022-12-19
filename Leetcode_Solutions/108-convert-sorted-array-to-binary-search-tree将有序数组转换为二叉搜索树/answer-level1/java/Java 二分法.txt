```
class Solution {
    public TreeNode sortedArrayToBST(int[] nums) {
        return helper(0, nums.length - 1, nums);
    }
    
    private TreeNode helper(int l, int h, int[] nums) {
        if (l > h) {
            return null;
        }
        
        int m = l + (h - l) / 2;
        TreeNode root = new TreeNode(nums[m]);
        root.left = helper(l, m - 1, nums);
        root.right = helper(m + 1, h, nums);
        
        return root;
    }
}
```