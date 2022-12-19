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
        if (root == null) {
            return 0;
        }
        List<TreeNode> leftLeafNodes = new ArrayList<>();
        process(root, false, leftLeafNodes);
        int result = 0;
        for (TreeNode treeNode : leftLeafNodes) {
            result += treeNode.val;
        }
        return result;
    }
    /**
     * 将左叶子节点存到 leftTreeNodes 中
     *
     * @param root          节点
     * @param isLeft        标志该节点是否为左孩子
     * @param leftTreeNodes 存放左叶子节点的 List
     */
    private void process(TreeNode root, boolean isLeft, List<TreeNode> leftTreeNodes) {
        if (isLeft && (root.left == null && root.right == null)) {
            /* 如果是左叶子结点，则存放到 leftLeafNodes 中 */
            leftTreeNodes.add(root);
        }
        if (root.left != null) {
            /* 如果是左子树不为空，则继续 */
            process(root.left, true, leftTreeNodes);
        }
        if (root.right != null) {
            /* 如果是右子树不为空，则继续 */
            process(root.right, false, leftTreeNodes);
        }
    }
}
```
