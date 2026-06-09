### 解题思路
![image.png](https://pic.leetcode-cn.com/fbf8ac417d5fa34a065661a650c4686f5ea384f7518db18caa5e4d05ebaaf5ef-image.png)

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
    public boolean hasPathSum(TreeNode root, int sum) {
        if (root == null) {
            return false;
        }
        if (root.right != null || root.left != null) {
            return hasPathSum(root.left, sum - root.val) || hasPathSum(root.right, sum - root.val);
        }
        return sum == root.val;
    }
}
```