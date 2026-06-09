[Leetcode-Java(更多题解，持续更新)](https://github.com/pphdsny/Leetcode-Java/blob/master/src/pp/arithmetic/leetcode/_98_isValidBST.java)

```java
    /**
     * 解题思路：
     * 树的解题思路：递归
     * 1.左子树满足条件
     * 2.右子树满足条件
     * 3.自己满足条件(大于左子树max，跟小于又子树min)
     *
     * @param root
     * @return
     */
    public boolean isValidBST(TreeNode root) {
        return valid(root, Integer.MIN_VALUE, Integer.MAX_VALUE);
    }

    private boolean valid(TreeNode root, int min, int max) {
        if (root == null) return true;
        if (root.val <= min || root.val >= max) return false;
        return valid(root.left, min, root.val) && valid(root.right, root.val, max);
    }

```