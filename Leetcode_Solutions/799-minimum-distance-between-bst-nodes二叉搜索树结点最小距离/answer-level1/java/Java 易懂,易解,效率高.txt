1.中序遍历二叉搜索树得到的是有序结点;
2.定义一个辅助结点temp,用于存放上一个节点,当pre不为空即从第二个节点开始记录二叉搜索树中两个节点差值的最小值即可;
3.完结。


        TreeNode pre;
        int min = Integer.MAX_VALUE;

        public int minDiffInBST(TreeNode root) {
            inorder(root);
            return min;
        }

        public void inorder(TreeNode node) {
            if (node == null)
                return;

            inorder(node.left);
            if (pre != null) {
                min = Math.min(min, node.val - pre.val);
            }
            pre = node;
            inorder(node.right);
        }