### 解题思路
递归

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
    private int v;
    public boolean isUnivalTree(TreeNode root) {
        v=root.val;
        return helper(root);
    }
    private boolean helper(TreeNode node){
        if (node==null)
            return true;
        else if (node.val!=v)
            return false;
        else
            return helper(node.left)&&helper(node.right);
    }
}
```