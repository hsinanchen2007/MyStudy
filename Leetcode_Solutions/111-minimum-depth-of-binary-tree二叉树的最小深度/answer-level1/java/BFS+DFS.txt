# BFS
思路: 遍历每一层并计数，若找到叶子节点直接返回
```
class Solution {
    public int minDepth(TreeNode root) {
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
                if (tmp.left == null && tmp.right == null) return depth;
                if (tmp.left != null) queue.add(tmp.left);
                if (tmp.right != null) queue.add(tmp.right);
            }
        }
        return depth;
    }
}
```
时间复杂度: O(n)
空间复杂度: O(h)
# DFS
思路: 
自上而下: 当前树的最小深度 = min(左子树最小深度, 右子树最小深度) + 1
自下而上: 若知道左右子树最小深度, 当前子树深度= min(左子树最小深度, 右子树最小深度) + 1
```
class Solution {
    public int minDepth(TreeNode root) {
        if (root == null) return 0;
        int left = minDepth(root.left);
        int right = minDepth(root.right);
        return (left == 0 || right == 0) ? left + right + 1 : Math.min(left, right) + 1;
    }
}
```
时间复杂度: O(n)
空间复杂度: O(h)
