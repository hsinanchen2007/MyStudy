**1.关注代码的规范性,完整性,鲁棒性;
2.此题和 二叉树的层序遍历,ZigZag遍历,每个树行中找最大值相似度极高,在迭代层序遍历基础上稍稍改进即可;
3.完结。**


        public List<Double> averageOfLevels(TreeNode root) {
            List<Double> list = new ArrayList<>();
            if (root == null)
                return list;

            Queue<TreeNode> queue = new LinkedList<>();
            queue.add(root);
            while (!queue.isEmpty()) {
                int length = queue.size();
                double sum = 0;
                for (int i = 0; i < length; i++) {
                    TreeNode cur = queue.poll();
                    sum += cur.val;
                    if (cur.left != null)
                        queue.add(cur.left);
                    if (cur.right != null)
                        queue.add(cur.right);
                }
                list.add(sum / length);
            }
            return list;
        }