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
    public boolean isUnivalTree(TreeNode root) {
        if (null == root)
            return true;
        return helper(root, root.val);
    }

    private boolean helper(TreeNode root, int val) {
        if (null == root)
            return true;
        if (root.val != val)
            return false;
        
        return helper(root.left, val) && helper(root.right, val);
    }
}
```