利用优先级队列，将两棵树中的节点添加到优先级队列中，再挨个取出。

```
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public List<Integer> getAllElements(TreeNode root1, TreeNode root2) {
        Queue<Integer> queue = new PriorityQueue<>();
        preorder(root1, queue);
        preorder(root2, queue);

        List<Integer> ans = new ArrayList<>();
        while (!queue.isEmpty()) {
            ans.add(queue.remove());
        }
        return ans;
    }

    private void preorder(TreeNode root, Queue<Integer> queue) {
        if (root == null) return;

        queue.offer(root.val);
        preorder(root.left, queue);
        preorder(root.right, queue);
    }
}
```
