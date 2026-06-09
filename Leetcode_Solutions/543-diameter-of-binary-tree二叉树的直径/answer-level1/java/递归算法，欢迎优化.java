### 解题思路
注意最长路径可能不经过根节点

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
    private int max = 0;
    public int diameterOfBinaryTree(TreeNode root) {
        if(root == null) {
            return 0;
        }

        max =  Math.max(maxLength(root.left) + maxLength(root.right), max);
        return max;
    }

    private int maxLength(TreeNode root) {
        if(root == null) {
            return 0;
        }

        int maxLeft = maxLength(root.left);
        int maxRight = maxLength(root.right);
        max = Math.max(maxLeft + maxRight, max);

        return Math.max(maxLeft, maxRight) + 1;
    }
}
```