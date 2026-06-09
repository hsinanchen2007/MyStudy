![image.png](https://pic.leetcode-cn.com/a54c8ec8112f7fc59653c6ed62d8ae6898fa83fe250570d31480b06db3d8d2c2-image.png)
👇

```
    int maxSum = Integer.MIN_VALUE;
    int maxPointSum = Integer.MIN_VALUE; //把顶点作为拐点的最大值
    public int maxPathSum(TreeNode root) {
        int r = dfs(root.right);
        int l = dfs(root.left);
        return Math.max(Math.max(maxSum, root.val + (r > 0 ? r : 0) + (l > 0 ? l : 0)), maxPointSum);
    }
    private int dfs(TreeNode root) {
        if(root == null) {
            return 0;
        }
        int l = dfs(root.left);
        int r = dfs(root.right);
        int m = Math.max(l, r);
        int sum1 = root.val + (m > 0 ? m : 0);
        maxSum = (sum1 > maxSum) ? sum1 : maxSum;
        int sum2 = root.val + (l > 0 ? l : 0) + (r > 0 ? r : 0);
        maxPointSum = (sum2 > maxPointSum) ? sum2 : maxPointSum;
        //只返回那些一条龙的，不返回拐弯的，因为一条龙的不能被上面顶点用了
        return sum1; 
    }
```



