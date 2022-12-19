```
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 * 关键点1：只用专注于一层（任意一层），假设子任务 deleteNode(root.left) 已完成。
 * 关键点2：root.left = deleteNode(root.left); 保存返回节点，递归固定模式。
 */
class Solution {
    public TreeNode deleteNode(TreeNode root, int key) {
        // 递归出口：适用于最简单的情况， 也适用于后续递归情况
        if (root == null) return null;

        if (key < root.val) {
            root.left = deleteNode(root.left, key);
        } else if (key > root.val) {
            root.right = deleteNode(root.right, key);
        } else {
            // 度为 2 的情况
            if (root.left != null && root.right != null) {
                // 在右子树中寻找最小值节点
                TreeNode node = minValueOfRight(root.right);
                root.val = node.val;
                // !!!
                root.right = deleteNode(root.right, node.val);
            } else {
                // 度为 0 或 1 的情况，二选一的情况，得加 else
                TreeNode child = root.left != null ? root.left : root.right;
                return child;
            }
        }

        return root;
    }

    private TreeNode minValueOfRight(TreeNode x) {
        while (x.left != null) {
            x = x.left;
        }
        return x;
    }
}
```
