//递归判断A和A的左节点和右节点包不包含B
class Solution {
    public boolean isSubStructure(TreeNode A, TreeNode B) {
        if(A == null || B == null){return false;}
        return isSameStrut(A,B) || isSubStructure(A.left,B) || isSubStructure(A.right,B);
    }
    public static boolean isSameStrut(TreeNode A,TreeNode B){
        if(B==null){return true;}
        if(A == null && B != null){ return false;}
        if(A.val != B.val){return false;}
        return isSameStrut(A.left,B.left) && isSameStrut(A.right,B.right);
    }
}