### 解题思路

时间复杂度**O(N)**，空间复杂度**O(N)**

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
    public TreeNode constructMaximumBinaryTree(int[] nums) {
        TreeNode[] stack = new TreeNode[nums.length + 1];
        int p = 1;
        stack[0] = new TreeNode(Integer.MAX_VALUE);
        for (int i : nums) {
            TreeNode node = new TreeNode(i);
            while (stack[p - 1].val < i) node.left = stack[--p];
            stack[p - 1].right = node;
            stack[p++] = node;
        }
        return stack[0].right;
    }
}
```