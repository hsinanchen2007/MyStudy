```
public int maxDepth(TreeNode root) {
    if (null == root)
        return 0;

    int deep = 0;
    TreeNode last = root, nextLast = null;

    Queue<TreeNode> queue = new LinkedList<>();
    queue.add(root);
    while (!queue.isEmpty()) {
        TreeNode node = queue.poll();
        if (null != node.left) {
            queue.add(node.left);
            nextLast = node.left;
        }
        if (null != node.right) {
            queue.add(node.right);
            nextLast = node.right;
        }

        if (last == node) {
            last = nextLast;
            deep++;
        }
    }
    return deep;
}
```
