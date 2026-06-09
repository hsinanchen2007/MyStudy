### 解题思路
题目中要高度平衡的二叉树，所以左右子节点数量相差不能超过1，所以必须求出来排序数组中的中间数字。

本来我想用 `(left + right) / 2`，但是这样会导致下标溢出，所以我用了`(left + (right - left) / 2)`来确定数组中的中间数字。

之后用这个数字来作为二叉树的根节点。

同理，子树也可以通过这种方法在数组中划区域进行。

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
        return converseDFS(nums, 0, nums.length - 1);
    }

    private TreeNode converseDFS(int[] nums, int left, int right) {
        if (left <= right) {
            int mid = left + (right - left) / 2;
            TreeNode root = new TreeNode(nums[mid]);
            root.left = converseDFS(nums, left, mid - 1);
            root.right = converseDFS(nums, mid + 1, right);
            return root;
        }
        return null;
    }

}
```