/**
     * 方法1
     * @param root root
     * @return 集合
     */
    private static List<List<Integer>> levelOrderBottom(TreeNode root) {
        List<List<Integer>> listList = new ArrayList<>();
        if (root == null) {
            return listList;
        }

        Deque<TreeNode> deque = new LinkedList<>();
        deque.add(root);
        while (!deque.isEmpty()) {
            List<Integer> list = new ArrayList<>();
            int currentSize = deque.size();
            for (int i=0; i<currentSize; i++) {
                TreeNode node = deque.pop();
                list.add(node.val);
                if (node.left != null) {
                    deque.add(node.left);
                }
                if (node.right != null) {
                    deque.add(node.right);
                }
            }
            listList.add(list);
        }
        Collections.reverse(listList);
        return listList;
    }