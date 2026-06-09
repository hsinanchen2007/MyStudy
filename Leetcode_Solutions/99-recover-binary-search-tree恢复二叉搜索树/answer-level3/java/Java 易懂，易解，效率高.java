**1.关注代码的规范性,完整性,鲁棒性;**

**2.法1法2区别在于前者中序遍历用的递归,后者用的栈,本质无区别;**

**3.此题的关键在于找到两个错误节点,分两种情况:(1)如果中序遍历出现了两次降序,那么第一个错误结点是第一次降序时较大的结点,第二个错误结点是第二次降序时较小的点;(2)如果中序遍历只有一次降序的话,那么第一个错误结点是此次降序较大的结点,第二个错误结点是此次降序较小的结点。**

**4.此题也可以调整树结构来调整两个错误结点,因zz水平有限,你懂得;**

**5.完结。**




法1:

        TreeNode first = null;
        TreeNode second = null;
        TreeNode pre = null;

        public void recoverTree(TreeNode root) {
            inorderTraversal(root);
            int temp = first.val;
            first.val = second.val;
            second.val = temp;
        }

        public void inorderTraversal(TreeNode root) {
            if (root == null)
                return;
            inorderTraversal(root.left);
            if (pre != null) {
                if (first == null && pre.val > root.val)
                    first = pre;
                if (first != null && pre.val > root.val)
                    second = root;
            }
            pre = root;
            inorderTraversal(root.right);
        }

法2：

        TreeNode first = null;
        TreeNode second = null;

        public void recoverTree(TreeNode root) {
            inorderTraversal(root);
            int temp = first.val;
            first.val = second.val;
            second.val = temp;
        }

        public void inorderTraversal(TreeNode root) {
            Stack<TreeNode> stack = new Stack<>();
            TreeNode pre = null;
            while (root != null || !stack.isEmpty()) {
                while (root != null) {
                    stack.push(root);
                    root = root.left;
                }
                root = stack.pop();
                if (pre != null) {
                    if (first == null && pre.val > root.val)
                        first = pre;
                    if (first != null && pre.val > root.val)
                        second = root;
                }
                pre = root;
                root = root.right;
            }
        }