思路：

根节点只与其第一层子节点相邻，即如果偷了根节点，则除了其第一层的左右子节点不能偷外，其第二层所有子节点都是可以偷的，反之，如果不偷根节点，则其第一层左右子节点可以偷，但其第二层子节点都不可以偷。

假设我们知道了当前节点第一层左右节点上能偷到的最大金额，又知道了其第二层所有子节点能偷的最大金额，则当前节点能偷到的最大金额就等于 Max(当前节点值 + 第二层所有子节点的值， 第一层左节点能偷的最大金额 + 第一层右节点能偷的最大金额)，这样就得出了我们的状态转移方程，依据这个方程去递归遍历所有节点即可得到结果；

直接上代码：
```
    public int rob(TreeNode root) {
        if(root == null) {
            return 0;
        }
        //左孩子节点能偷的最大金额
        int leftMoney = rob(root.left);
        //右孩子节点能偷的最大金额
        int rightMoney = rob(root.right);
        //左孩子的左孩子节点能偷的最大金额
        int leftChildLeftMoney = 0;
        //左孩子的右孩子节点能偷的最大金额
        int leftChildRightMoney = 0;
        //右孩子的左孩子节点能偷的最大金额
        int rightChildLeftMoney = 0;
        //右孩子的右孩子节点能偷的最大金额
        int rightChildRightMoney = 0;
        if(root.left != null) {
            leftChildLeftMoney = rob(root.left.left);
            leftChildRightMoney = rob(root.left.right);
        }
        if(root.right != null) {
            rightChildLeftMoney = rob(root.right.left);
            rightChildRightMoney = rob(root.right.right);
        }
        //比较第一层孩子节点的金额总和与第二层所有孩子节点金额总和加上当前节点金额的最大值，即为结果
        return Math.max(leftMoney + rightMoney, root.val + leftChildLeftMoney + leftChildRightMoney + rightChildLeftMoney + rightChildRightMoney);
    }
```
