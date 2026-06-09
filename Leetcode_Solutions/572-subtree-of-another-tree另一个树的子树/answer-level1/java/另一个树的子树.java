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
    public boolean isSubtree(TreeNode s, TreeNode t) {
        if(s==null&&t==null)
          return true;
        if(s==null)
            return false;
        if(s.val==t.val)
            return isEqual(s,t)||isSubtree(s.left,t)||isSubtree(s.right,t);
        else
            return isSubtree(s.left,t)||isSubtree(s.right,t);
    }

    public boolean isEqual(TreeNode s,TreeNode t)
    {
        //判断两个树是否相等，递归写法
        if(s==null&&t==null)
            return true;
        if(s==null||t==null)  //有一个为空，另一个不为空，
            return false;
        if(s.val==t.val)
            return isEqual(s.left,t.left)&&isEqual(s.right,t.right);
        return false;
    }
}
```