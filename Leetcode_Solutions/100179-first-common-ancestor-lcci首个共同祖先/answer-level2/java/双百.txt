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
    TreeNode res = null;
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
      postorder(root, p, q);
        return res;
    }
    
    public boolean postorder(TreeNode root, TreeNode p, TreeNode q){
        if(root == null || res != null)
            return false;
        
        boolean left = postorder(root.left, p, q);
        boolean right = postorder(root.right, p, q);
        
        if(left && right){
            res = root;
            return true;
        }
        if(left || right){
            if(root == p || root == q){
                res = root;               
            }
            return true;
        }
        if(root == p || root == q)
            return true;
        else
            return false;
        
    }
}
```