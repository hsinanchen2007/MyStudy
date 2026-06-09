后序遍历数据：
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
    
    private TreeNode result = null;

    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        result = null;
        lowestCommonAncestorCompute(root, p, q);
        return result;
    }


    private int lowestCommonAncestorCompute(TreeNode root, TreeNode p, TreeNode q) {
        // 已经查找完毕
        if (result != null || root == null) {
            return 0;
        }
        // 还需要接着查找。
        int fill = lowestCommonAncestorCompute(root.left, p, q) + lowestCommonAncestorCompute(root.right, p, q);
        // 根节点包含
        if (root.val == p.val || root.val == q.val) {
            fill += 1;
        }

        if (fill == 2 && result == null) {
            result = root;
        }
        return fill;
    }
}
```