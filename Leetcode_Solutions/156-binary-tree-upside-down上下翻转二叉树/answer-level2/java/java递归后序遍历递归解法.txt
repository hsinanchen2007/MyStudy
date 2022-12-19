### 解题思路
java递归后序遍历递归解法。helper返回的是新树中的右节点，而最终要返回新的root，所以一开始需要把新的root保存下来。

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
    
    TreeNode finalNewRoot = null;
    
    public TreeNode upsideDownBinaryTree(TreeNode root) {
        
        if(root == null || (root.left==null && root.right==null) )
        {
            return root;
        }
        
        helper(root);
        
        return finalNewRoot;
        
    }
    
    
    public TreeNode helper(TreeNode root)
    {
        if(root==null)
        {
            return null;
        }
        

        
        TreeNode newRootNode = helper(root.left);
        TreeNode newLeftNode = helper(root.right);
        TreeNode newRightNode = root;
        
        if(newRootNode==null)
        {
          
            
            return root;
        }        
        
        if(finalNewRoot==null)
        {
           finalNewRoot = newRootNode;       
        }
        
        newRootNode.left = newLeftNode;
        newRootNode.right = newRightNode;
        
        if(newLeftNode!=null)
        {
            
            newLeftNode.left = null;
            newLeftNode.right = null;            

        }
        
        
        if(newRightNode!=null)
        {
            newRightNode.left = null;
            newRightNode.right = null;
    
        }
        
        return newRightNode;
        
        
    }
}
```