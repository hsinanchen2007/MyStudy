# DFS
**思路:**
自下而上: 如果知道左右子树的高, 那么当前，树高= max(左子树高, 右子树高) + 1
自上而下: 当前树高 = max(左子树高, 右子树高) + 1
```
class Solution {
    public int maxDepth(TreeNode root) {
        return root == null ? 0 : Math.max(maxDepth(root.left), maxDepth(root.right)) + 1;
    }
}
```
时间复杂度: O(n)
空间复杂度: O(h)
# BFS
**思路: 每访问一层就累加计数器**
```
class Solution {
    public int maxDepth(TreeNode root) {
        if (root == null) return 0;
        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);
        int depth = 0;
        //visited
        while (!queue.isEmpty()) {
            int size = queue.size();
            ++depth;
            for (int i = 0; i < size; ++i) {
                TreeNode tmp = queue.poll();
                if (tmp.left != null) {
                    queue.add(tmp.left);
                }
                if (tmp.right != null) {
                    queue.add(tmp.right);
                }
            }
        }
        return depth;
    }
}
```
时间复杂度: O(n)
空间复杂度: O(h)
