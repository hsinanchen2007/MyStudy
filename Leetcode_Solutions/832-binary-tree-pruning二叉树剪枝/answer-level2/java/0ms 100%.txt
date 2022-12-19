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
    public TreeNode pruneTree(TreeNode root) {
        if (helper(root))
            return root;
        return null;
    }
    private boolean helper(TreeNode node){
        if (node==null)
            return false;
        if (node.val==1){
            if (!helper(node.left))
                node.left=null;
            if (!helper(node.right))
                node.right=null;
            return true;
        }
        else {
            boolean left=helper(node.left);
            boolean right=helper(node.right);
            if (!left)
                node.left=null;
            if (!right)
                node.right=null;
            return left || right;
        }
    }
}
```