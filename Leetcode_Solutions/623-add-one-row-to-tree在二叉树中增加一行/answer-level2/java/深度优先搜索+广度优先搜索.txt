```java
    public TreeNode addOneRow(TreeNode root, int v, int d) {
        // return bfs(root, v, d);
        return dfs(root, v, d, true);
    }

    public TreeNode dfs(TreeNode root, int v, int d, boolean isLeft) {
        if (d == 1) {
            TreeNode nRoot = new TreeNode(v);
            if (isLeft) {
                nRoot.left = root;
            } else {
                nRoot.right = root;
            }
            return nRoot;
        }
        if (root != null) {
            root.left = dfs(root.left, v, d - 1, true);
            root.right = dfs(root.right, v, d - 1, false);
        }
        return root;
    }

    public TreeNode bfs(TreeNode root, int v, int d) {
        if (d == 1) {
            TreeNode nRoot = new TreeNode(v);
            nRoot.left = root;
            return nRoot;
        }
        int n = 2;
        Queue<TreeNode> queue = new ArrayDeque<>();
        queue.offer(root);
        while (n < d) {
            n++;
            int size = queue.size();
            TreeNode node;
            while (size-- > 0) {
                node = queue.remove();
                if (node.left != null) {
                    queue.offer(node.left);
                }
                if (node.right != null) {
                    queue.offer(node.right);
                }
            }
        }
        TreeNode node;
        TreeNode left;
        TreeNode right;
        while (!queue.isEmpty()) {
            node = queue.remove();
            left = node.left;
            right = node.right;
            node.left = new TreeNode(v);
            node.left.left = left;
            node.right = new TreeNode(v);
            node.right.right = right;
        }
        return root;
    }
```
