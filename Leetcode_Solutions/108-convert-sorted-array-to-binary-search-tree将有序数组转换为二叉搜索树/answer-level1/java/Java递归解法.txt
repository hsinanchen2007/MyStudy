利用归并排序的思想，直接定位BST中节点在数组中的位置。
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
      if(nums.length == 0){
        return null;
      }
      return sortedArrayToBST(nums,0,nums.length - 1);
    }
    private TreeNode sortedArrayToBST(int[] nums,int l,int h){
      if(l > h){
        return null;
      }
      int m = l + (h - l)/2;
      TreeNode root = new TreeNode(nums[m]);
      root.left = sortedArrayToBST(nums,l,m - 1);
      root.right = sortedArrayToBST(nums,m + 1,h);
      return root;
    }
}
```
