### 解题思路
左孩子和右孩子都空，对称
左孩子和右孩子一个空一个不空，不对称
左右相等->左孩子的左孩子等于右孩子的右孩子&&左孩子的右孩子等于右孩子的左孩子，对称
左右不相等->不对称


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
       public  boolean isSymmetric(TreeNode root) {
          return LeftAndRightTreeisSymmetric(root,root);
    }
    
    public  boolean LeftAndRightTreeisSymmetric(TreeNode q,TreeNode p){
          if(q==null&&p==null)
              return true;
          if(q==null||p==null)
              return false;
          if(q.val==p.val){
              return LeftAndRightTreeisSymmetric(q.left,p.right)&&LeftAndRightTreeisSymmetric(q.right,p.left);
          }

        return false;
    }

}
```