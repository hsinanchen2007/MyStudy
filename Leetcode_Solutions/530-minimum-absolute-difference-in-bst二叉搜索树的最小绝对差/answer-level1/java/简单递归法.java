1. 如果当前给定节点的左子树不为空，则将当前节点与左子树的最大值作比较，得到的值为当前节点与左子树的最小差值，并先将此作为最小差值.
2. 找出左子树中任意两个节点的最小差值，与当前最小差值作比较，将更小的差值作为最新的最小差值.
3. 同理，使用上述两个步骤对当前节点的左子树做处理.
4. 由于树为二叉搜索树，所以左右两个节点的差值一定小于父节点与左右节点的差值，所以无需计算两个子节点的差.
5. 当被判断的某个树没有左右子树时，则返回整形最大值.（题目给的二叉搜索树至少有两个节点，所以最终结果不会是整形最大值）.

```
class Solution2 {
    public int getMinimumDifference(TreeNode root) {
        if (root.left == null && root.right == null) {
            return Integer.MAX_VALUE;
        }
        int min = Integer.MAX_VALUE;
        if (root.left != null) {
            int value1 = Math.abs(root.val - maxNode(root.left).val);
            min = min < value1 ? min : value1;
            int value2 = getMinimumDifference(root.left);
            min = min < value2 ? min : value2;
        }
        if (root.right != null) {
            int value1 = Math.abs(root.val - minNode(root.right).val);
            min = min < value1 ? min : value1;
            int value2 = getMinimumDifference(root.right);
            min = min < value2 ? min : value2;
        }
        return min;
    }
    //取得二叉搜索树中值最大的节点
    private TreeNode maxNode(TreeNode node) {
        return node.right == null ? node : maxNode(node.right);
    }
    //取得二叉搜索树中值最小的节点
    private TreeNode minNode(TreeNode node) {
        return node.left == null ? node : minNode(node.left);
    }
}
```
