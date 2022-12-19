经提醒，已更新
需要判断当前节点是否大于左子树最大值并且小于右子树最小值
```
class Solution {
    
    class Meta {
        boolean valid;
        int sum;
        int min;
        int max;
        public Meta(boolean valid, int sum, int min, int max) {
            this.valid = valid;
            this.sum = sum;
            this.min = min;
            this.max = max;
        }
    }
    
    private int max = 0;
    
    public int maxSumBST(TreeNode root) {
        dfs(root);
        return max;
    }
    
    private Meta dfs(TreeNode node) {
        if (node == null) {
            return new Meta(true, 0, 0, 0);
        }
        Meta left = dfs(node.left);
        Meta right = dfs(node.right);
        max = Math.max(max, Math.max(left.sum, right.sum));
        if (left.valid && right.valid && (node.left == null || left.max < node.val) && (node.right == null || right.min > node.val)) {
            Meta res = new Meta(true, left.sum + right.sum + node.val, node.left == null ? node.val : left.min, node.right == null ? node.val : right.max);
            max = Math.max(max, res.sum);
            return res;
        }
        return new Meta(false, 0, 0, 0);
    }
}
```
