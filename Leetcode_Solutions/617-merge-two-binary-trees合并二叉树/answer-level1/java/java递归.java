

最初的思考：
1、判断两个二叉树t1,t2是否为空，为空返回另一个；
2、通过递归分别前序遍历二叉树，修改t1当作返回二叉树，当t1,t2同时为空时，递归结束；
3、每次都是当前节点相加，但是如果下个左右节点为空，则加一个节点并赋值为0；

    public TreeNode mergeTrees(TreeNode t1, TreeNode t2) {
    if(t1 == null) return t2 ;
    if(t2 == null) return t1 ;
    return a1(t1, t2) ;
    }

    public TreeNode a1(TreeNode t1, TreeNode t2) {
    if(t1 == null && t2 == null) return null ;

    t1.val = t1.val + t2.val ;

    if(t1.left == null && t2.left != null) t1.left = new TreeNode(0) ;
    if(t1.left != null && t2.left == null) t2.left = new TreeNode(0) ;
    if(t1.right == null && t2.right != null) t1.right = new TreeNode(0) ;
    if(t1.right != null && t2.right == null) t2.right = new TreeNode(0) ;

    mergeTrees(t1.left, t2.left) ;
    mergeTrees(t1.right, t2.right) ;

    return t1 ;
    }

可以同过返回值来给左右节点赋值，来抵消new一个节点；
递归结束的条件就不是同时为0，则是一个为空范围另外一个值，
修改之后：
    public TreeNode mergeTrees(TreeNode t1, TreeNode t2) {
    if(t1 == null) return t2 ;
    if(t2 == null) return t1 ;
        
    t1.val = t1.val + t2.val ;
    	
    t1.left = mergeTrees(t1.left, t2.left) ;
    t1.right = mergeTrees(t1.right, t2.right) ;
    
    return t1 ;
    }