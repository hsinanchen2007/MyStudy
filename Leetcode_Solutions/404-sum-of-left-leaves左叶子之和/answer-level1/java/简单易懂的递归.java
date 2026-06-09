执行用时 : 1 ms, 在所有 Java 提交中击败了99.28%的用户
内存消耗 :34.8 MB, 在所有 Java 提交中击败了80.00%的用户

```
class Solution {
    int ans = 0;
    public int sumOfLeftLeaves(TreeNode root) {
        dfs(root);
        return ans;
    }
    
    public void dfs(TreeNode node){
        if (node == null ) return;
        if (node.left != null && node.left.left==null && node.left.right==null) ans += node.left.val;
        dfs(node.left);
        dfs(node.right);
    }
}
```
