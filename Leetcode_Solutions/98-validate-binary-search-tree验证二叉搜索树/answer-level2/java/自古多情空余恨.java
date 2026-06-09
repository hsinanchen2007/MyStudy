### 解题思路
树遍历 若节点 超出（树上届 树下届）则return false

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
        return isValidBST(root,null,null) ;
    }
    public boolean isValidBST(TreeNode root,Integer low , Integer upper) {
        if (root == null )
            return true ;

        if (low!= null && root.val <= low )
            return false ;
        
        if (upper!= null && root.val >= upper )
            return false ;
                        
    
        return  isValidBST(root.left,low ,root.val) && isValidBST(root.right,root.val,upper) ;
    }
}
```