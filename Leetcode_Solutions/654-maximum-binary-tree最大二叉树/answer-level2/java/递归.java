### 解题思路
递归处理即可，每次找到数组的最大值，然后设置好左右子节点。

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
    int[] nums;
    public TreeNode constructMaximumBinaryTree(int[] nums) {
        this.nums = nums;
        return buildTree(0, nums.length);
    }

    public TreeNode buildTree(int left, int right) {
        if (left == right) {
            return null;
        }
        int maxInt = nums[left];
        int index = left;
        for (int i=left+1;i<right;i++) {
            if (maxInt < nums[i]) {
                maxInt = nums[i];
                index = i;
            }
        }
        TreeNode node = new TreeNode(maxInt);
        TreeNode leftNode = buildTree(left, index);
        TreeNode rightNode = buildTree(index+1, right);
        node.left = leftNode;
        node.right = rightNode;
        return node;
    }

}
```