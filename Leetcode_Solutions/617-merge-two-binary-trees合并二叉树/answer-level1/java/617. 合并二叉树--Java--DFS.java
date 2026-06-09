[Leetcode-Java(200+题解，持续更新、欢迎star)](https://github.com/pphdsny/Leetcode-Java/blob/master/src/pp/arithmetic/leetcode/_617_mergeTrees.java)

```java
    /**
     * 解题思路：
     * 对于数的题目基本是DFS递归
     * 1、构建父节点，如t1、t2的不为null，使其加和
     * 2、构建子树节点，将t2、t2对应位置传递过去，重复步骤1
     *
     * @param t1
     * @param t2
     * @return
     */
    public TreeNode mergeTrees(TreeNode t1, TreeNode t2) {
        if (t1 == null && t2 == null) {
            return null;
        }
        //1、构建父节点
        TreeNode node = new TreeNode(0);
        if (t1 != null) node.val += t1.val;
        if (t2 != null) node.val += t2.val;
        //2、构建子树节点
        node.left = mergeTrees(t1 == null ? null : t1.left, t2 == null ? null : t2.left);
        node.right = mergeTrees(t1 == null ? null : t1.right, t2 == null ? null : t2.right);
        return node;
    }
```