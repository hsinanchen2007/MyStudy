递归二分建树。找到数组的中间那个数作为树的根节点，那么这个数左边的数用同样的方法递归出根节点的左子树，这个数右边的数用同样的方法递归出根节点的右子树。
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
    public TreeNode sortedArrayToBST(int[] nums) {
        return buildTree(nums, 0, nums.length - 1);
    }
    
    private TreeNode buildTree(int[] nums, int left, int right) {
        if (left > right)
            return null;
        int m = left + ((right - left) >> 1);
        TreeNode root = new TreeNode(nums[m]);
        root.left = buildTree(nums, left, m - 1);
        root.right = buildTree(nums, m + 1, right);
        
        return root;
    }
}
```
