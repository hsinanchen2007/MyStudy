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
    /**
    **《子结构不完全相等》
    */
    public boolean isSubStructure(TreeNode A, TreeNode B) {
        if(A == null || B == null) return false;
        if(A.val == B.val){
            return isMatch(A,B) || isSubStructure(A.left,B) || isSubStructure(A.right,B);
        }
        return isSubStructure(A.left,B) || isSubStructure(A.right,B);
        
    }
    public static boolean isMatch(TreeNode A,TreeNode B){
        if(A == null || B == null) return false;
        if(A.val == B.val){
            boolean isMatchFlag = true;
            if(B.left != null){
                isMatchFlag = isMatchFlag && isMatch(A.left,B.left);
            }
            if(B.right != null){
                isMatchFlag = isMatchFlag && isMatch(A.right,B.right);
            }
            return isMatchFlag;
        }
        return false;
    }
    /**
    **《子结构完全相等》
    */
    public boolean isSubStructure2(TreeNode A, TreeNode B) {
        if(A == null && B == null) return true;
        if(A == null || B == null) return false;
        if(A.val == B.val){
            return isEqual(A,B) || isSubStructure(A.left,B) || isSubStructure(A.right,B);
        }
        return isSubStructure(A.left,B) || isSubStructure(A.right,B);
        
    }
    public boolean isEqual(TreeNode A,TreeNode B){
        if(A == null && B == null) return true;
        if(A == null || B == null) return false;
        if(A.val == B.val){
            return isEqual(A.left,B.left) && isEqual(A.right,B.right);
        }
        return false;
    }
}
```