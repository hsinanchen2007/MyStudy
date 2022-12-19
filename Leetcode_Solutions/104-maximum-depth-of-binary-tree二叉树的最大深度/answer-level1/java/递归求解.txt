
//深度是指root节点到任意节点的路径（边数），最大深度就是root节点到叶子节点的最大边数      
public  int maxDepth(TreeNode root) {

        if (root ==null){//为null 直接返回
            return 0;
        }
            int l = maxDepth(root.left)+1;//递归计算左节点到叶子节点最大深度 + 1
            int r  = maxDepth(root.right)+1;////递归计算右节点到叶子节点最大深度+1
            return  Math.max(l,r);//最大节点

        }