```
class Solution {
    public boolean isSubStructure(TreeNode A, TreeNode B) {
        if(B == null || A == null) return false;
        return (A.val == B.val && isMatch(A,B)) || isSubStructure(A.left,B) || isSubStructure(A.right,B);
    }

    boolean isMatch(TreeNode A, TreeNode B){
        if(A==null) return B==null;
        if(B==null) return A==null;
        if(A.val == B.val){
            return (B.left!=null && isMatch(A.left,B.left) || B.left==null) && 
                   (B.right!=null && isMatch(A.right,B.right) || B.right == null);
        }
        return false;
    }
}
```
