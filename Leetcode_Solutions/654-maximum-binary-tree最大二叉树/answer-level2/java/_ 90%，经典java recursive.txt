```
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public TreeNode constructMaximumBinaryTree(int[] nums) {
        // recursive
        return f(nums, 0, nums.length - 1);
    }

    private TreeNode f(int[] nums, int start, int end) {
        if(start > end)
            return null;
        int biggest = start;
        for(int i = start; i <= end; ++ i) {
            if(nums[i] > nums[biggest])
                biggest = i;
        }
        TreeNode cur = new TreeNode(nums[biggest]);
        cur.left = f(nums, start, biggest - 1);
        cur.right = f(nums, biggest + 1, end);
        return cur;
    } 
}
```
