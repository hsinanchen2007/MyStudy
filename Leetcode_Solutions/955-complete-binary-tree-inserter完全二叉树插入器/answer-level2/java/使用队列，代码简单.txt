使用一个队列按层序保存完全二叉树所有【还可以继续插入新节点】的节点。
然后每次插入时，只需要在队列的第一个位置的节点插入即可。

```java
class CBTInserter {
    // 保存有一个或两个null指针的节点
    private Queue<TreeNode> queue = new ArrayDeque<>();
    private TreeNode root;
    public CBTInserter(TreeNode root) {
        this.root = root;
        queue.add(root);
        while (queue.element().left != null && queue.element().right != null) {
            TreeNode node = queue.remove();
            queue.add(node.left);
            queue.add(node.right);
        }
        if (queue.element().left != null)
            queue.add(queue.element().left);
    }
    
    public int insert(int v) {
        TreeNode node = queue.element();
        if (node.left == null) {
            queue.add(node.left = new TreeNode(v));
        } else {
            queue.add(node.right = new TreeNode(v));
            queue.remove();
        }
        return node.val;
    }
    
    public TreeNode get_root() {
        return this.root;
    }
}
```