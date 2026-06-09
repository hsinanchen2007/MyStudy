### 解题思路
此处撰写解题思路
观察可得  最大长度 = 左子树的最大高度 + 右子树的最大高度
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
    int max = Integer.MIN_VALUE;

    public int diameterOfBinaryTree(TreeNode root) {
        helper(root);
                return max == Integer.MIN_VALUE ? 0 : max;

    }
    public int helper(TreeNode root) {
        if (root == null) {
            return 0;
        }
        int right = helper(root.right);
        int left = helper(root.left);
        max =  Math.max(left + right, max);
        return Math.max(left, right) + 1;
    }
}
```