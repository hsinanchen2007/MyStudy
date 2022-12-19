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
    public int sumOfLeftLeaves(TreeNode root) {
        return dfs(root, false); // 根节点非叶子结点
    }
    /**
     * dfs
     * @param node 当前节点
     * @param isLeft 是否为左子树
     * @return 左子树的叶节点和
     */
    private int dfs(TreeNode node, boolean isLeft) {
        if (node != null) { // 节点是否为空
            if (isLeft && node.left == null && node.right == null) { // 是左叶子节点
                return node.val;
            } else {
                return dfs(node.left, true) + dfs(node.right, false); // 返回左右的和
            }
        }
        return 0; // 空节点返回0
    }
}
```
