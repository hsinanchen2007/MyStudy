**1.关注代码的规范性，完整性，鲁棒性。
2.法一法二都采用了一个flag来判断是否检测到了null值;
3.法一按照层序遍历的顺序依次从左至右放入队列中,如果第一次遇到null值,则改变flag为true,跳出当前循环继续下次循环,如果还有不为null的值,则返回false,否则遍历完剩余null的队列;
4.法二判断当前节点的左右子节点,如果左孩子为null右孩子不为null,返回false,如果已经遇到null那么flag就为true,那么再有左右孩子不为null就返回false,将不为null的左右孩子放入队列,如果右孩子不为null的话就改变flag的值为true,意为之后不能再有不为null的值出现;
5.完结。**

法一：

        public boolean isCompleteTree(TreeNode root) {
            if (root == null)
                return true;

            Queue<TreeNode> queue = new LinkedList<>();
            queue.add(root);
            boolean flag = false;
            TreeNode cur = null;
            while (!queue.isEmpty()) {
                cur = queue.poll();
                if (cur == null) {
                    flag = true;
                    continue;
                }
                if (flag)
                    return false;
                queue.add(cur.left);
                queue.add(cur.right);
            }
            return true;
        }

法二：

        public boolean isCompleteTree(TreeNode root) {
            if (root == null)
                return true;

            Queue<TreeNode> queue = new LinkedList<>();
            queue.add(root);
            boolean flag = false;
            while (!queue.isEmpty()) {
                TreeNode cur = queue.poll();
                TreeNode l = cur.left;
                TreeNode r = cur.right;
                if (l == null && r != null)
                    return false;
                if (flag && (l != null || r != null))
                    return false;

                if (l != null)
                    queue.add(l);
                if (r != null)
                    queue.add(r);
                else
                    flag = true;
            }
            return true;
        }