### 解题思路


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
        return recursion(root, null, null);
    }

    private boolean recursion(TreeNode root, TreeNode predecessor, TreeNode successor) {
        if (root == null) return true;
        if (predecessor != null && successor == null) {
            if (root.val <= predecessor.val) return false;
        }
        if (successor != null && predecessor == null) {
            if (root.val >= successor.val) return false;
        }
         if (successor!=null && predecessor!=null){
            if (root.val <= predecessor.val || root.val >= successor.val ) return false;
        }
        //if (root.val < predecessor.val || root.val > successor.val) return true;
        return recursion(root.left, predecessor, root) && recursion(root.right, root, successor);
    }



}
```