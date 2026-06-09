

```java
    // 反例！项目中千万别这么写代码
    public boolean hasPathSum(TreeNode root, int sum) {
        if (root == null) return false; // 没有子节点直接返回 false
        return ((sum -= root.val) == 0 && root.right == null && root.left == null) || (hasPathSum(root.left, sum) || hasPathSum(root.right, sum));
    }

    // 正例：这样写舒服多了
    public boolean hasPathSum(TreeNode root, int sum) {
        if (root == null) return false; // 没有子节点直接返回 false
        sum -= root.val;
        if (sum == 0 && root.right == null && root.left == null) return true;
        return hasPathSum(root.left, sum) || hasPathSum(root.right, sum);
    }    
```