执行用时 :1 ms, 在所有 Java 提交中击败了99.64%的用户

内存消耗 :35 MB, 在所有 Java 提交中击败了79.79%的用户

简单的小分治算法，思路：

1. 如果当前节点有左子节点，交给一个isLeft函数去处理
2. 如果当前节点有右子节点，交给一个isRight函数去处理

> 两函数区别：**如果传到isLeft函数里面的节点没有子节点，那么最后结果加上当前节点的value**

代码如下：

	private int sum = 0;

    public int sumOfLeftLeaves(TreeNode root) {
        sum = 0;
        if(root == null) return sum;
        if(root.left != null) isLeft(root.left);
        if(root.right != null) isRight(root.right);
    	return sum;
    }
    
    public void isLeft(TreeNode left) {
    	if(left.left == null && left.right == null) sum += left.val;
    	if(left.left!=null) isLeft(left.left );
    	if(left.right != null) isRight(left.right);
    }
    
    public void isRight(TreeNode right) {
    	if(right.left!=null) isLeft(right.left );
    	if(right.right != null) isRight(right.right);
    }