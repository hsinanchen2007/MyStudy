执行用时 : 1 ms, 在所有 Java 提交中击败了95.88%的用户
内存消耗 : 39 MB, 在所有 Java 提交中击败了100.00%的用户

```
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> res = new ArrayList<>();
        if (root != null) {
            Queue<TreeNode> queue = new LinkedList<>();
            queue.add(root);
            int current = 1;
            int next = 0;
            List<Integer> sub = new ArrayList<>();
            while (!queue.isEmpty()) {
                TreeNode node = queue.remove();
                sub.add(node.val);
                current--;
                if (node.left != null) {
                    queue.add(node.left);
                    next++;
                }
                if (node.right != null) {
                    queue.add(node.right);
                    next++;
                }
                if (current == 0) {
                    res.add(new ArrayList<>(sub));
                    sub.clear();
                    current = next;
                    next = 0;
                }
            }
        }
        return res;
    }
```
