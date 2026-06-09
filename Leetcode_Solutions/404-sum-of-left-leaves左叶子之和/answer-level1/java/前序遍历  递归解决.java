  递归解决    

    int leftSum = 0;
    public int sumOfLeftLeaves(TreeNode root) {
        if (root == null){
            return 0;
        }
        if (root.left != null && root.left.left == null && root.left.right == null){
         leftSum += root.left.val;
        }
        sumOfLeftLeaves(root.left);
        sumOfLeftLeaves(root.right);
        return leftSum;
    }