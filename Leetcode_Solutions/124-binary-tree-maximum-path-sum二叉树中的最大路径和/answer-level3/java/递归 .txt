- solve(root)  方法表示以root 为起始点，路径最大值 root.val + Math.max(Math.max(lMax, 0), Math.max(rMax, 0))
- max 维护整个的最大值


```
    private int max = Integer.MIN_VALUE;
    public int maxPathSum(TreeNode root) {
        if(root == null) return 0;
        solve(root);
    
        return max;
    }
    
    private int solve(TreeNode root){
        if(root == null) return 0;
        
        int val = root.val;
        int lMax = solve(root.left);
        int rMax = solve(root.right);
        
        int temp = val + Math.max(lMax, 0) + Math.max(rMax, 0);
        max = Math.max(max, temp);
                       
        return val + Math.max(Math.max(lMax, 0), Math.max(rMax, 0));
    }
```