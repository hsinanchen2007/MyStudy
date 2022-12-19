

``` 
    public boolean isValidBST(TreeNode root) {
        return helper(root, Long.MIN_VALUE, Long.MAX_VALUE);
    }
    ////设立上界最大值和下界最小值，最大值和最小值调用数据类型Long中的最大值和最小值。如果用Integer的话会出错，因为有一个测试用例只有一个结点，值恰好等于integer的最大值
    private boolean helper(TreeNode root,Long min,Long max){
        if (root==null) return true;
        if (root.val<=min||root.val>=max)
            return false;
        //左节点一定小于根节点，所以将根节点的值设为最大。
        //右结点一定大于根节点。所以将根节点的值设为最小
        return helper(root.left, min, (long) root.val)&&helper(root.right, (long) root.val,max);
    }
``` 