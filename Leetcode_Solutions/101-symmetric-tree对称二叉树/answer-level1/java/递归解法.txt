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
     public boolean isSymmetric(TreeNode root) {
      return   treeEquals(root,root);
    }

      public boolean treeEquals(TreeNode t1, TreeNode t2) {
        if (t1 == null && t2 == null) {
            return true;
        } else if (t1 == null || t2 == null) {
            return false;
        }

        return  t1.val==t2.val&&treeEquals(t1.left, t2.right) && treeEquals(t1.right, t2.left);
    }


}
```
递归比较好理解
镜像的话 只要保证 t1.val==t2.val&&treeEquals(t1.left, t2.right) && treeEquals(t1.right, t2.left)