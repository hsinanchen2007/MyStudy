[Leetcode-Java(200+题解，持续更新、欢迎star)](https://github.com/pphdsny/Leetcode-Java/blob/master/src/pp/arithmetic/leetcode/_543_diameterOfBinaryTree.java)

```java
    private int ret = 0;

    /**
     * 解题思路：
     * 对于树的问题，正常思路就是遍历，此题也不例外
     * 如题所示，找到最长的路径，有两种可能：
     *  一、根节点+左右子树节点
     *  二、根节点+最长的子树节点作为其父节点的子节点
     * 递归遍历过程中，用一个全局变量保存遍历过程中的最大值
     *
     * @param root
     * @return
     */
    public int diameterOfBinaryTree(TreeNode root) {
        dfs(root);
        return ret;
    }

    private int dfs(TreeNode root) {
        if (root == null) return 0;
        int left = dfs(root.left);
        int right = dfs(root.right);
        int count = left + right;
        ret = Math.max(ret, count);
        return Math.max(left, right) + 1;
    }
```