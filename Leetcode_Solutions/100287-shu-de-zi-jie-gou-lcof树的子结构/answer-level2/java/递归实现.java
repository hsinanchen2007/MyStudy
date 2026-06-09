### 解题思路
首先通过递归找到与B根节点相同的节点，再从该节点开始寻找是否具有相同的树结构。

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
        if(A.val != B.val){
            return isSubStructure(A.left,B) || isSubStructure(A.right,B);
        }
        return isSub(A,B);
    }

    public boolean isSub(TreeNode A, TreeNode B){
        if(A == null) return false;
        if(A.val != B.val) return false;
        if(B.left == null && B.right == null) return true;
        else if(B.left == null) return isSub(A.right,B.right);
        else if(B.right == null) return isSub(A.left,B.left);
        else return isSub(A.left,B.left) && isSub(A.right,B.right);

    }

}
```