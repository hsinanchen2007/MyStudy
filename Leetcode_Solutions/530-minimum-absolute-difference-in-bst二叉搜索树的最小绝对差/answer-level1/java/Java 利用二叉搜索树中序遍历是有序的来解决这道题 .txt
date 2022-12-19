![捕获.PNG](https://pic.leetcode-cn.com/ac341747f1f10123a7a2ca50cb165d5046f76eb5eb85ff22a2a2400956dc00b6-%E6%8D%95%E8%8E%B7.PNG)
```
class Solution {
    int ans = Integer.MAX_VALUE;
    int min = Integer.MAX_VALUE;
    public int getMinimumDifference(TreeNode root) {
        if (root != null) {
            
            getMinimumDifference(root.left);
            min = Math.min(min, Math.abs(root.val - ans));
            ans = root.val;
            getMinimumDifference(root.right);
        }
        return min;
    }
}
```

