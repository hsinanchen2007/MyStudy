> 执行用时 :0 ms, 在所有 Java 提交中击败了 100.00% 的用户
> 内存消耗 : 41.7 MB, 在所有 Java 提交中击败了 100.00% 的用户

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
        return sortedArrayToBST(0, nums.length - 1, nums);
    }

    private TreeNode sortedArrayToBST(int left, int right, int[] nums) {
        if(left > right) {
            return null;
        }
        int mid = (left + right) / 2;
        // 每次都选中间的节点作为根节点
        TreeNode tree = new TreeNode(nums[mid]);
        tree.left = sortedArrayToBST(left, mid - 1, nums);
        tree.right = sortedArrayToBST(mid + 1, right, nums);
        return tree;
    }
}
```