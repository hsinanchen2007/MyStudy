先上代码
```
class Solution {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        // 其中一个能深搜到另一个（直接祖先）
        if (DFS(p, q)) return p;
        if (DFS(q, p)) return q;
        TreeNode ret = root;
        int depth = 0, maxDepth = -1;
        LinkedList<TreeNode> queue = new LinkedList<>();
        queue.offer(root);
        // 层序遍历
        while (!queue.isEmpty()) {
            TreeNode head = queue.poll();
            if (head.left != null) queue.offer(head.left);
            if (head.right != null) queue.offer(head.right);
            if (DFS(head, p) && DFS(head, q) && depth > maxDepth) {
                maxDepth = depth;
                ret = head;
            }
            depth += 1;
        }
        return ret;
    }
    public boolean DFS(TreeNode root, TreeNode target) {
        if (root == null) return false;
        if (root.val == target.val) return true;
        return DFS(root.left, target) || DFS(root.right, target);
    }
}
```
思路很简单：
层序遍历这棵二叉树；
在每一次循环取出队首结点时，从这个node出发，看看是否能同时搜到p和q；
如果能，说明这个node是公共祖先；
在遍历过程中记录深度，保留深度最深的公共祖先，即为最近公共祖先。
