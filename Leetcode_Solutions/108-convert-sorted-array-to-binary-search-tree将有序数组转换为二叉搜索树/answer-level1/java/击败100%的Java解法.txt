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
      return getSubtree(nums, 0, nums.length - 1);
    }

    private TreeNode getSubtree(int[] nums, int start, int last) {
        if (start > last) {
            return null;
        }
        int mid = start + (last - start) / 2;
        TreeNode root = new TreeNode(nums[mid]);
        root.left = getSubtree(nums, start, mid - 1);
        root.right = getSubtree(nums, mid + 1, last);
        return root;
    }
}
```