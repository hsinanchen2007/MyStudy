中序遍历的迭代方法的拆分写法。

```java
    // 中序遍历-分摊为每个子树的遍历
    class BSTIterator {
        private final Deque<TreeNode> queue = new LinkedList<>();

        public BSTIterator(TreeNode node) {
            while (node != null) {
                queue.addLast(node);
                node = node.left;
            }
        }

        public int next() {
            TreeNode curr = queue.pollLast();
            TreeNode node = curr.right; // 右子树遍历
            while (node != null) {
                queue.addLast(node);
                node = node.left;
            }
            return curr.val;
        }

        public boolean hasNext() {
            return !queue.isEmpty();
        }
    }
```