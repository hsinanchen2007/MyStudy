思路就是考虑一个节点的子树。
如果子树的金币比它原本应得的多（或者少），就需要流经此节点减少（或者增大多少）。递归可得代码：
```
class Solution {
    
    private int count = 0;
    
    private int dfs(TreeNode root) {
        if (root.left == null && root.right == null) {
            return root.val - 1;
        }
        
        int left = 0;
        if (root.left != null) {
            left = dfs(root.left);
            count += Math.abs(left);
        }
        
        int right = 0;
        if (root.right != null) {
            right = dfs(root.right);
            count += Math.abs(right);
        }
        
        return root.val - 1 + left + right;
        
    }
    
    public int distributeCoins(TreeNode root) {
        dfs(root);
        
        return count;
    }
}
```
