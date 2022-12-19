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
    public boolean checkSubTree(TreeNode t1, TreeNode t2) {
        //判断t2是否是t1的子树
        if(t2==null)
            return true;
        if(t1==null&&t2!=null)
            return false;
        if(t1.val==t2.val)
            return checckEqualTree(t1,t2)||checkSubTree(t1.left,t2)||checkSubTree(t1.right,t2);
        else
            return checkSubTree(t1.left,t2)||checkSubTree(t1.right,t2);
    }

    //首先判断两个数是否相等
    public boolean checckEqualTree(TreeNode t1,TreeNode t2)
    {
        if(t1==null && t2==null)
            return true;
        if(t1==null||t2==null)
            return false;
        if(t1.val==t2.val)
            return checckEqualTree(t1.left,t2.left)&&checckEqualTree(t1.right,t2.right);
        else
            return false;
    }
}
```