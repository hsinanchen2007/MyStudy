// 对称二叉树
        // 左子树按（中左右顺序遍历）
        // 右子树按（中右左顺序遍历）
        // if val不等返回false，或一个为空一个不为空返回false

class Solution {
    public boolean isSymmetric(TreeNode root) {
        if(root==null)
        return true;
        TreeNode leftRoot = root.left;
        TreeNode rightRoot = root.right;
        return midleSearch(leftRoot,rightRoot);
    }
    public boolean midleSearch(TreeNode rootl,TreeNode rootr){
        if(rootl==null& rootr==null)
            return true;
        if(rootl==null | rootr == null)
            return false;
        if(rootl.val==rootr.val){
            boolean re1 = midleSearch(rootl.left,rootr.right);
            boolean re2 = midleSearch(rootl.right,rootr.left);
            return (re1 & re2);
        }else{
            return false;
        }
    }
}