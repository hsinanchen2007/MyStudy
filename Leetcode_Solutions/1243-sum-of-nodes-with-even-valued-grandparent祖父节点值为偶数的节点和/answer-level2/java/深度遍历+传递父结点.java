每次递归时传递父结点，在当前节点判断父结点是否为偶数，若为偶数，则满足条件，将其左右子节点值加到ans中。
```
class Solution {
    private int ans = 0;

    public int sumEvenGrandparent(TreeNode root) {
        dfs(root, null);
        return ans;
    }

    private void dfs(TreeNode root, TreeNode parent) {
        if (root == null) {
            return;
        }

        if (parent != null && parent.val % 2 == 0) {
            if (root.left != null) {
                ans += root.left.val;
            }
            if (root.right != null) {
                ans += root.right.val;
            }
        }
        dfs(root.left, root);
        dfs(root.right, root);
    }
}
```
