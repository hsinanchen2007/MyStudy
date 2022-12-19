### 解题思路
一句话，二分查找和中序遍历。

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
        if (nums == null || nums.length == 0) {
            return null;
        }

        return sortedArrayToBST(nums, 0, nums.length - 1);
    }

    public TreeNode sortedArrayToBST(int[] nums, int start, int end) {
        if (start > end) {
            return null;
        } else if (start == end) {
            return new TreeNode(nums[start]);
        }
        int mid = (end - start) / 2;
        TreeNode root = new TreeNode(nums[start + mid]);
        root.left = sortedArrayToBST(nums, start, start + mid - 1);
        root.right = sortedArrayToBST(nums, start + mid + 1, end);
        return root;
    }

}
```