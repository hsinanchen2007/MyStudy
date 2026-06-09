模仿谬先生的题解，使用Java。
在数组为有序（从大到小）的情况下，时间复杂度为O(n2)。

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
        if(nums == null || nums.length == 0){
            return null;
        }
        TreeNode node = new TreeNode(nums[0]);
        TreeNode curMax = node;
        int curIndex = 0;
        for(int i = 1; i < nums.length ; i++){
            //大于则将原来最大的节点置于其左
            if(nums[i] > nums[curIndex]){
                TreeNode temp = new TreeNode(nums[i]);
                temp.left = curMax;
                curMax = temp;
                curIndex = i;
            } else {
                //小于则遍历原最大节点的右子树，找到其合适的位置。
                TreeNode temp = curMax;
                while(temp.right != null){
                    TreeNode right = temp.right;
                    if(right.val > nums[i]){
                        temp = temp.right;
                    } else {
                        TreeNode temp1 = new TreeNode(nums[i]);
                        temp1.left = right;
                        temp.right = temp1;
                        break;
                    }
                }
                if(temp.right == null){
                    temp.right = new TreeNode(nums[i]);
                }
            }
        }
        return curMax;
    }
}
```