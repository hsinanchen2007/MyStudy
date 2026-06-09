### 解题思路
通俗简洁的递归方法：每次保存当前节点的上下界，由于会存在Integer_MAX_VALUE这样的节点，所以用Long.MIN_VALUE和Long.MAX_VALUE作为起始的界。

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
    public boolean isValidBST(TreeNode root) {
        return helper(root, Long.MIN_VALUE, Long.MAX_VALUE);
    }
    
    public boolean helper(TreeNode root, long min, long max) {
        if(root == null) {
            return true;
        }
        if(root.val > min && root.val < max) {           
            return helper(root.left, min, root.val) && helper(root.right, root.val, max);
        }
        return false;
    }
}
```