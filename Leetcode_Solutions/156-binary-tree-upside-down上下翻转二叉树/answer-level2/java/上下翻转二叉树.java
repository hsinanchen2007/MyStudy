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
    public TreeNode upsideDownBinaryTree(TreeNode root) {
        return helper(null,root);
    }

    public TreeNode helper(TreeNode parent,TreeNode node){
        if(node==null)
            return parent;
        TreeNode ret=helper(node,node.left);
        if(parent!=null)
        {
            node.left=parent.right;
        }
        else{
            node.left=null; 
        }
        node.right=parent;
        return ret;
    }
}
```