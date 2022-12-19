### 解题思路
递归解决，挺简单的

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
    public TreeNode sortedArrayToBST(int[] nums) {
        if(nums == null || nums.length == 0) return null;
        return helper(nums, 0, nums.length - 1);
    }

    private TreeNode helper(int[] nums, int start, int end){
        // 出口
        if(start == end) return new TreeNode(nums[start]);
        if(start > end) return null;

        int index = (end + start) / 2;
        // 找出根元素，作为根节点
        TreeNode root = new TreeNode(nums[index]);
        // 找出左子节点，作为左子节点
        root.left = helper(nums, start, index - 1);
        root.right = helper(nums, index + 1, end);

        return root;
    }
}
```