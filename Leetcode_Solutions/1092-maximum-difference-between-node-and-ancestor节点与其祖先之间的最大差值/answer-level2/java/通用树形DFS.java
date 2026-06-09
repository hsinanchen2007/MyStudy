```
class Solution {
    private int ans = 0;
    private int tmpMax = Integer.MIN_VALUE;
    private int tmpMin = Integer.MAX_VALUE;

    public int maxAncestorDiff(TreeNode root) {
        dfs(root);
        return ans;
    }

    private void dfs(TreeNode node) {
        if (node == null) {
            return;
        }
        int preMax = tmpMax, preMin = tmpMin;
        tmpMax = Math.max(tmpMax, node.val);
        tmpMin = Math.min(tmpMin, node.val);
        if (node.left == null && node.right == null) {
            ans = Math.max(ans, tmpMax - tmpMin);
        }
        if (node.left != null) {
            dfs(node.left);
        }
        if (node.right != null) {
            dfs(node.right);
        }
        tmpMax = preMax;
        tmpMin = preMin;
    }
}
```
