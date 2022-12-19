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
    public TreeNode sortedArrayToBST(int[] nums) {
        if (nums == null) {
            return null;
        }
        return buildTree(nums, 0, nums.length - 1);
    }

    private TreeNode buildTree(int[] nums, int start, int end) {
        if(start > end) {
            return null;
        }
        
        TreeNode node = new TreeNode(nums[(start + end) / 2]);
        node.left = buildTree(nums, start, (start + end) / 2 - 1);
        node.right = buildTree(nums, (start + end) / 2 + 1, end);
        
        return node;
    }
}
```