```java
    public TreeNode addOneRow(TreeNode root, int v, int d) {
        if (d == 1) {
            TreeNode node = new TreeNode(v);
            node.left = root;
            return node;
        }
        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);
        int depth = 1;
        TreeNode temp;
        while (!queue.isEmpty()) {
            // 当深度为d-1退出, 此时队列中只保留了d-1层的节点
            if (depth == d - 1) break;
            int size = queue.size();
            while (size-- > 0) {
                temp = queue.remove();
                if (temp.left != null)
                    queue.add(temp.left);
                if (temp.right != null)
                    queue.add(temp.right);
            }
            depth++;
        }
        // 遍历d-1层的节点, 该层节点的左右节点都要设置, 不管是否为空
        TreeNode parent;
        while (!queue.isEmpty()) {
            parent = queue.remove();

            temp = new TreeNode(v);
            temp.left = parent.left;
            parent.left = temp;

            temp = new TreeNode(v);
            temp.right = parent.right;
            parent.right = temp;
        }
        return root;
    }
```