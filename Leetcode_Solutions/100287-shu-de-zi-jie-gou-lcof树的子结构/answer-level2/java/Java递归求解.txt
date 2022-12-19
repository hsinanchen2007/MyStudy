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
    public boolean isSubStructure(TreeNode A, TreeNode B) {
        if(A==null) return false;
        if(B==null) return false;
        int headB=B.val;
        if(A.val==headB) return isSameHelper(A,B);
        return isSubStructure(A.left,B)||isSubStructure(A.right,B);
    }
    public boolean isSameHelper(TreeNode A,TreeNode B)
    {
         if(A==null&&B!=null) return false;
         if(A==null||B==null) return true;
          return A.val==B.val&&isSameHelper(A.left,B.left)&&isSameHelper(A.right,B.right);
    }
}
```