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
        TreeNode root = null;
        root = buildTree(nums, root, 0, nums.length - 1);
        return root;
    }
    public TreeNode buildTree(int[] nums, TreeNode root, int start, int end) {
        if (start <= end) {
            int mid = (start + end) / 2;
            root = new TreeNode(nums[mid]);
            root.left = buildTree(nums, root.left, start, mid - 1);
            root.right = buildTree(nums, root.right, mid + 1, end);
        }
        return root;
    }
}
```