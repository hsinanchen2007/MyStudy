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
    // ------- 方法1 -------

    // n * lon n
    public boolean isBalanced1(TreeNode root) {
        if (root == null) return true;
        if (Math.abs(treeHeight(root.left) - treeHeight(root.right)) > 1)
            return false;
        return isBalanced(root.left) && isBalanced(root.right);
    }

    // 求树高
    int treeHeight(TreeNode root) {
        if (root == null) return 0;
        return Math.max(treeHeight(root.left), treeHeight(root.right)) + 1;
    }

    // ------- 方法2 -------

    // 一次遍历，log n
    public boolean isBalanced2(TreeNode root) {
        return isBalancedAndHeight(root)[0] == 1;
    }

    int[] isBalancedAndHeight(TreeNode root) {
        int[] ret = new int[2];
        ret[0] = 1;
        if (root == null) return ret;
        int[] left = isBalancedAndHeight(root.left);
        int[] right = isBalancedAndHeight(root.right);
        ret[1] = Math.max(left[1], right[1]) + 1;
        if (left[0] == 0 || right[0] == 0) ret[0] = 0;
        if (Math.abs(left[1] - right[1]) > 1) ret[0] = 0;
        return ret;
    }
}
```