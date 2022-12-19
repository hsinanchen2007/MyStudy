比较两颗树是否对称，从中间拉一条竖线 用此竖线分割的已经找到的对称的两个节点 假设已经找到一组节点A,B  如果A的左子树的值==B的右子树的值 且 如果A的右子树的值==B的左子树的值 则A，B是镜像对称的
用递归很容易实现：

 public boolean isSymmetric(TreeNode root) {
        return contrast(root,root);
    }

    public boolean contrast(TreeNode root1,TreeNode root2){
        if(root1==null&&root2==null)
            return true;
        if(root1!=null&&root2!=null&&root1.val==root2.val){
           return contrast(root1.left,root2.right)&& contrast(root1.right,root2.left);
        }
        return false;
    }

