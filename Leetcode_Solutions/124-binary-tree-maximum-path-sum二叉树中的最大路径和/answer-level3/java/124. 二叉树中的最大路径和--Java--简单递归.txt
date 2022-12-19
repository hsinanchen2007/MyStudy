[Leetcode-Java(更多题解，持续更新)](https://github.com/pphdsny/Leetcode-Java/blob/master/src/pp/arithmetic/leetcode/_124_maxPathSum.java)

```java
    private int maxPath = Integer.MIN_VALUE;

    /**
     * 解题思路：
     * 树的解题离不开递归遍历
     * 1.寻找左子树的最大路径和（负数抛弃）
     * 2.寻找右子树的最大路径和（负数抛弃）
     * 3.如根节点是整数（含0），合并左右子树中的正数（负数不要），比较已存在得最大值
     * 4.返回结果是根节点、根节点+左子树、根节点+右子树的最大值
     * <p>
     * 注意：
     * 1.因为求的是连续路径，如果子树的最大值中根节点未参数计算，不应该加入子树父节点的计算
     * 2.可能存在左、右子树都是可以用的，但是路径不能走回头路，只能返回左右子树和根节点的最大值
     *
     * @param root
     * @return
     */
    public int maxPathSum(TreeNode root) {
        maxPath = Integer.MIN_VALUE;
        dfs(root);
        return maxPath;
    }

    private int dfs(TreeNode root) {
        if (root == null) return 0;
        //1
        int leftMax = dfs(root.left);
        //2
        int rightMax = dfs(root.right);
        //3
        int max = root.val;
        if (leftMax > 0) max += leftMax;
        if (rightMax > 0) max += rightMax;
        maxPath = Math.max(maxPath, max);
        //4
        return Math.max(root.val, Math.max(root.val + leftMax, root.val + rightMax));
    }
```