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
    public boolean isSymmetric(TreeNode root) {
        if (root == null)
            return true ;
        return isReverseTree(root.left,root.right) ;
    }

    public boolean isReverseTree(TreeNode tree1 , TreeNode tree2) {
        if ( tree1 == null && tree2 == null)
            return true ;
        if ( (tree1 == null  && tree2 != null ) ||
             (tree2 == null  && tree1 != null ) ||
             tree1.val != tree2.val ) {
                 return false ;
        }

        return isReverseTree(tree1.left,tree2.right) && isReverseTree(tree1.right,tree2.left) ;
    }
}
```