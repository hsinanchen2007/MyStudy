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
    
    public TreeNode next;
    
    public void flatten(TreeNode root) {
        helper(root);
    }
    
    public void helper(TreeNode root)
    {
        if(root==null)
        {
            return;
        }
        
        helper(root.right);        
        helper(root.left);
        root.right = next;
        root.left = null;
        
        next = root;
        
    }
}
```