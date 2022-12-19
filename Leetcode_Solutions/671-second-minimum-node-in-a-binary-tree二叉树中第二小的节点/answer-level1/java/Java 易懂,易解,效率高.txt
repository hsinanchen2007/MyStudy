1.第二小的数字：定义两个变量存放第一小和第二小的数字;
2.其中特别注意的是count计数器,如果二叉树只有一个数字的话,意味着second没有被赋值,那么count等于0,输出-1;如果count 大于0 那么就输出second;
3.有什么不对或者可以优化的地方大佬尽管提出来,鄙人会加以优化和改正;
4.完结。



        int first = Integer.MAX_VALUE, second = Integer.MAX_VALUE;
        int count = 0;

        public int findSecondMinimumValue(TreeNode root) {
            helper(root);
            return count == 0 ? -1 : second;
        }

        public void helper(TreeNode root) {
            if (root == null)
                return;

            if (root.val < first) {
                second = first;
                first = root.val;
            } else if (root.val <= second && root.val > first) {
                count++;
                second = root.val;
            }
            helper(root.left);
            helper(root.right);
        }