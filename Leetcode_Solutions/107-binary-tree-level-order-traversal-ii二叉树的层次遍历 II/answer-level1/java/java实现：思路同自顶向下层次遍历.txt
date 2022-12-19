```
    /**
     * 时间复杂度O(n)
     * 空间复杂度O(n)
     * 
     * 整体思路和自定的二叉树层次遍历相同，
     * 唯一区别在于：遍历完每一层时，放入结果集时采用头插入addFirst
     * 这样输出结果集时，底层在上。
     * @param root 根节点
     * @return 层次遍历结果
     */
    public List<List<Integer>> levelOrderBottom(TreeNode root) {
        LinkedList<List<Integer>> result = new LinkedList<>();
        if (root == null) {
            return result;
        }
        LinkedList<TreeNode> queue = new LinkedList<>();
        queue.add(root);
        while (!queue.isEmpty()) {
            int size = queue.size();
            LinkedList<Integer> levels = new LinkedList<>();
            for (int i = 0; i < size; i++) {
                TreeNode node = queue.poll();
                levels.add(node.val);
                if (node.left != null) {
                    queue.add(node.left);
                }
                if (node.right != null) {
                    queue.add(node.right);
                }
            }
            //区别点：头插入
            result.addFirst(levels);
        }
        return result;
    }
```
