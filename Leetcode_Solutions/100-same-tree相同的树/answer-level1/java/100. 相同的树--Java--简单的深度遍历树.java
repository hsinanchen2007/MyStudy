[Leetcode-Java(200+题解，持续更新、欢迎star&留言&交流)](https://github.com/pphdsny/Leetcode-Java/blob/master/src/pp/arithmetic/leetcode/_100_isSameTree.java)

```java
    /**
     * 解题思路：
     * 典型的树的深度遍历（DFS）
     * 1、判断左子树是否相同
     * 2、判断右子树是否相同
     * 3、判断父节点是否相同
     *
     * @param p
     * @param q
     * @return
     */
    public boolean isSameTree(TreeNode p, TreeNode q) {
        if (p== null && q == null) return true;
        if (p == null || q == null) return false;
        return isSameTree(p.left,q.left) && isSameTree(p.right,q.right) && p.val == q.val;
    }
```