### 解题思路
广度优先搜索，避免使用递归造成的大量节点的无用遍历

### 代码

```java
    // bfs
    public int minDepth(TreeNode root) {
        if (root == null) {
            return 0;
        }
        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(root);
        int depth = 0;
        boolean isEnd = false;
        while (!queue.isEmpty()) {
            depth++;
            int n = queue.size();
            while (n-- > 0) {
                TreeNode node = queue.poll();
                if (node.left == null && node.right == null) {
                    isEnd = true;
                    break;
                }
                if (node.left != null) {
                    queue.offer(node.left);
                }
                if (node.right != null) {
                    queue.offer(node.right);
                }
            }
            if (isEnd) {
                break;
            }

        }
        return depth;

    }
```