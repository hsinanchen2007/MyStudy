### 解题思路
此处撰写解题思路

### 代码

```java
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
             
                 TreeNode node = new TreeNode(returnMax(nums));
                 int index = returnIndex(nums);
                 if (index>0){
                     node.left = constructMaximumBinaryTree(Arrays.copyOfRange(nums,0,index));
                 }
                 if (index == 0){
                     node.left =null;
                 }
                 if (index<nums.length-1){
                     node.right = constructMaximumBinaryTree(Arrays.copyOfRange(nums,index+1,nums.length));
                 }
                 if (index == nums.length-1){
                     node.right = null;
                 }
                 return node;
    }
    private int returnMax(int[] nums){
        int max = Integer.MIN_VALUE;
        for (int num:nums) {
            max = Math.max(max,num);
        }
        return max;
    }
    private int returnIndex(int[] nums){
        int max = Integer.MIN_VALUE;
        int index = -1;
        for (int i = 0; i < nums.length; i++) {
            if (max < nums[i]){
                max = nums[i];
                index = i;
            }
        }
        return index;
    }
}
```