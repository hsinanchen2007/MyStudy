**1.关注代码的规范性,完整性,鲁棒性;
2.此题和257二叉树的所有路径思想一样;
3.遍历整个二叉树的路径,定义一个局部sum和最后要返回的sumNum,sum存储每一条二叉树路径的和,当root的左右孩子都为null时,那么就到了路径底部,将局部sum和当前节点的val与sumNum相加即可;
4.完结。**


        int sumNum = 0;

        public int sumNumbers(TreeNode root) {
            if (root == null)
                return 0;
            helper(root, 0);
            return sumNum;
        }

        public void helper(TreeNode root, int sum) {
            if (root.left == null && root.right == null) {
                sumNum += sum + root.val;
            }
            if (root.left != null)
                helper(root.left, sum * 10 + root.val * 10);
            if (root.right != null)
                helper(root.right, sum * 10 + root.val * 10);
        }