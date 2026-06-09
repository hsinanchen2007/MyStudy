### 解题思路

要使二叉树的高度最小，且数组已是升序，递归的构建二叉子树，子树的根结点为数组中间节点，递归地构建子树左孩子和子树的右孩子


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
        return nums == null ? null : buildTree(nums, 0, nums.length - 1);
    }

    public TreeNode buildTree(int[] nums, int start, int end) {
        if (start <= end) {
            int mid = (end + start + 1)/2;
            TreeNode root = new TreeNode(nums[mid]);
            root.left = buildTree(nums, start, mid - 1);
            root.right = buildTree(nums, mid + 1, end);
            return root;
        }
        return null;
    }
}
```