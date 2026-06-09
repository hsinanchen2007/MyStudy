### 解题思路
//1.找出A中出现B的值的结点n1
//2.遍历以n1和B为结点的树，能够继续遍历的条件是两棵树遍历时刻的左右结点值相同。结束条件是A或B的所有结点都比较过了。

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
        if(A == null || B == null) return false;
        TreeNode n1 = searchBroot(A,B);
        if(n1 == null)
            return false;
        return isEquals(n1,B);
    }
    public boolean isEquals(TreeNode A, TreeNode B) {
        if(A == null && B == null)
            return true;
        if(B == null)
            return true;
        if(A == null)
            return false;
        if(A.val != B.val)
            return false;
        return isEquals(A.left,B.left) && isEquals(A.right,B.right) || (B.left == null && B.right == null) ;
    }

    public TreeNode searchBroot(TreeNode A,TreeNode B){
        if(A == null)
            return null;
        if(A.val == B.val)
            return A;
        TreeNode n1 = searchBroot(A.left,B);
        if(n1!=null)
            return n1;
        TreeNode n2 = searchBroot(A.right,B);
            return n2;
    }
}
```