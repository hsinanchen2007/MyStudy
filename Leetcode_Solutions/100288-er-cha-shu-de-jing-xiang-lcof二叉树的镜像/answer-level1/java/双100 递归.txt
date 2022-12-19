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
    public TreeNode mirrorTree(TreeNode root) {
        if (root==null)
            return null;
        TreeNode n=helper(root);
        return n;
    }
    private TreeNode helper(TreeNode node){
        if (node==null)
            return null;
        TreeNode mid=node.left;
        node.left=helper(node.right);
        node.right=helper(mid);
        return node;
    }
}
```