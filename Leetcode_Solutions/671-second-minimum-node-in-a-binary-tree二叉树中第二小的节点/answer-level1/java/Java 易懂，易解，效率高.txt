**1.关注代码的规范性,完整性,鲁棒性;
2.先序遍历整棵树,首先定义 first 和 second 分别接收第一小第二小值,初始化为最大值,count 表示 second 被赋值与否,如果 count == 0,那么此树为单值二叉树,所以返回 -1 ,如果count 不为 0,那么此树有两个及以上的值,当first < 第二小的值 <= second,count为1并为second赋值;
3.完结。**



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
            } else if (root.val > first && root.val <= second) {
                count++;
                second = root.val;
            }
            helper(root.left);
            helper(root.right);
        }