solve（root） 代表的含义是以 root 为初始节点最大路径和

```
    private int max = Integer.MIN_VALUE;
    public int maxPathSum(TreeNode root) {
        solve(root);
        return max;
    }
    
    private int solve(TreeNode root){
        if(root == null) return 0;
        
        int lVal = solve(root.left), rVal = solve(root.right), ans = root.val;
        ans += Math.max(Math.max(lVal, rVal), 0);
        max = Math.max(max, Math.max(ans, root.val+lVal+rVal));
        
        return ans;
    }
```
