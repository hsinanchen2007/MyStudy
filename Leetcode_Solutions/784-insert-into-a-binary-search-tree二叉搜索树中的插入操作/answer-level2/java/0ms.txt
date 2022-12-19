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
    public TreeNode insertIntoBST(TreeNode root, int val) {
        return helper(root,val);
    }
    private TreeNode helper(TreeNode node, int val){
        if (node==null)
            node=new TreeNode(val);
        else if (node.val>val)
            node.left=helper(node.left,val);
        else
            node.right=helper(node.right,val);
        return node;
    }
}
```