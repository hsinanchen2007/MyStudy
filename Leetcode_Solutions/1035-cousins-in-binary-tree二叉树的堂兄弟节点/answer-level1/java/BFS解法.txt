在BFS标签下找到的这题目，于是乎当然想着用BFS来解，解法上用数组 Tree[2] 来保存符合要求节点的父节点


执行用时 :1 ms, 在所有 Java 提交中击败了66.44% 的用户
内存消耗 :37.5 MB, 在所有 Java 提交中击败了5.29%的用户

我发现最近刷的BFS题，每一道都是递归被评判速度更快....

```
    public boolean isCousins(TreeNode root, int x, int y) {
        if (root == null) return false;
        TreeNode[] nodes = new TreeNode[2];
        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);
        while (!queue.isEmpty()) {
            int size = queue.size(), count = size;
            nodes[0] = nodes[1] = null;
            while (count > 0) {
                TreeNode top = queue.remove();
                if (top.left != null) {
                    queue.add(top.left);
                    if (top.left.val == x) nodes[0] = top;
                    if (top.left.val == y) nodes[1] = top;
                }
                if (top.right != null) {
                    queue.add(top.right);
                    if (top.right.val == x) nodes[0] = top;
                    if (top.right.val == y) nodes[1] = top;
                }
                --count;
            }
            if (nodes[0] == nodes[1] || nodes[0] == null || nodes[1] == null) continue;
            return true;
        }
        return false;
    }
```
