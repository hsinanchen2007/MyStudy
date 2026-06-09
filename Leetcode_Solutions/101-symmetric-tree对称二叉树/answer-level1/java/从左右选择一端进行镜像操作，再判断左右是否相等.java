对称则表示左右两端互为镜像，将镜像判断分解为两步：1.选择左端独自进行镜像操作 2.判断左端镜像操作后是否与右端各个节点值一致
两个小步骤则用递归的方式进行，也比较简单容易理解。

class Solution {
    public boolean isSymmetric(TreeNode root) {
        if(root==null){
            return true;
        }
        reverse(root.left);
        return isSame(root.left,root.right);
    }

//此函数用于判断两个节点是否各个子节点值相等
    public boolean isSame(TreeNode leftR,TreeNode rightR){
        if(leftR==null&&rightR!=null){
            return false;
        }
        if(rightR==null&&leftR!=null){
            return false;
        }
        if(rightR==null&&leftR==null){
            return true;
        }
        if(rightR.val==leftR.val){
            return isSame(rightR.left,leftR.left)&&isSame(rightR.right,leftR.right);
        }
        return false;
    }

//此函数用于将节点进行镜像操作
    public void reverse(TreeNode tn){
        if(tn!=null){
            TreeNode temp=tn.left;
            tn.left=tn.right;
            tn.right=temp;
            reverse(tn.left);
            reverse(tn.right);
        }
    }
}