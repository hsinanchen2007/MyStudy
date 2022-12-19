[Leetcode-Java(更多题解，持续更新)](https://github.com/pphdsny/Leetcode-Java/blob/master/src/pp/arithmetic/leetcode/_226_invertTree.java)

```java
    /**
     * 解题思路：
     * 树的经典解题：左、右、自己，递归遍历，拿到翻转后的左右子树，将root的左右子树坐下替换
     * 1.翻转左子树
     * 2.翻转右子树
     * 3.替换root的左右子树（翻转后）
     *
     *
     * @param root
     * @return
     */
    public TreeNode invertTree(TreeNode root) {
        if (root ==null) return null;
        //1
        TreeNode left = invertTree(root.left);
        //2
        TreeNode right = invertTree(root.right);
        //3
        root.left = right;
        root.right = left;
        return root;
    }
```