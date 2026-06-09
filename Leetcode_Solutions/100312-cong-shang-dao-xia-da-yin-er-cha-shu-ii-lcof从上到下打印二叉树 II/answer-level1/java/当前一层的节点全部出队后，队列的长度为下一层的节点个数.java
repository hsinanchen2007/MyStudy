写个比较通俗的解法
     * 规律：当前一层的节点全部出队后，队列的长度为下一层的节点个数
     *          例如，当根节点出队后，队列长度为2，为第二层的节点个数
     *       每次出队时，都将当前层的节点个数减1
     *       当levelSize为0时，代表这一层遍历完了



二叉树的层序遍历不验证，主要是每一层结果放在一个list中，
用变量levelSize来记录每一层的节点个数，
初始时使得根节点入队，levelSize = queue.size()，
根节点出队，levelSize - 1 = 0，
让根节点的左右子节点入队，
levelSize = 0，每一层遍历完，将第一层的结果存入链表，生成新的链表，
levelSize = queue.size()，继续循环
```
    public List<List<Integer>> levelOrder(TreeNode root) {
        if (root == null) return Collections.emptyList();

        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(root);
        int levelSize = queue.size();

        List<List<Integer>> res = new ArrayList<>();
        List<Integer> levelRes = new ArrayList<>();
        while (!queue.isEmpty()) {
            TreeNode node = queue.poll();
            levelRes.add(node.val);
            levelSize--;
            if (node.left != null) queue.offer(node.left);
            if (node.right != null) queue.offer(node.right);

            if (levelSize == 0) {
                levelSize = queue.size();
                res.add(levelRes);
                levelRes = new ArrayList<>();
            }
        }
        return res;
    }
```
