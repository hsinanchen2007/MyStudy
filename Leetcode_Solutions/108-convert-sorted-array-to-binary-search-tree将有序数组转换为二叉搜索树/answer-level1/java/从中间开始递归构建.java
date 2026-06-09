### 解题思路

从中间节点作为根节点开始，不断递归构造子树，最后得到目标二叉搜索树。

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
    TreeNode buildTree(int[] nums, int start, int end) {
        if (end == start) {
            return new TreeNode(nums[start]);
        }
        if (start > end) {
            return null;
        }
        int mid = start + (end - start) / 2;
        TreeNode tn = new TreeNode(nums[mid]);
        tn.left = buildTree(nums, start, mid - 1);
        tn.right = buildTree(nums, mid + 1, end);
        return tn;
    }

    public TreeNode sortedArrayToBST(int[] nums) {
        if (nums.length < 1) {
            return null;
        }
        return buildTree(nums, 0, nums.length - 1);
    }
}
```