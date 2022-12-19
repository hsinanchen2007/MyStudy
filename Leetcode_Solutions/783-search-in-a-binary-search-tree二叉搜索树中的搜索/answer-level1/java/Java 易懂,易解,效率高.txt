1.递归版本和迭代版本;
2.因为是二叉搜索树,所以判断条件可以写成如下;
3.完结。


    //递归
        public TreeNode searchBST(TreeNode root, int val) {
            if (root == null)
                return null;

            if (root.val > val) {
                return searchBST(root.left, val);
            } else if (root.val < val) {
                return searchBST(root.right, val);
            } else {
                return root;
            }
        }

    // 迭代
        public TreeNode searchBST(TreeNode root, int val) {
            while (root != null) {
                if (root.val == val) {
                    return root;
                } else if (root.val > val) {
                    root = root.left;
                } else {
                    root = root.right;
                }
            }
            return null;
        }