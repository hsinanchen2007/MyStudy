题目分析
根据题意，p、q必定存在于二叉树中，那么根据这一特性，可以得出公共祖先必定存在，有且只有三种情况：
1、p、q分别存在于左右子树
2、p为q的祖先
3、q为q的祖先

代码解释
分别递归左右子树并查询p、q节点，递归过程中会出现三种情况：
1、左右子树都返回空节点，则说明当前路径不存在p、q，而根据题意，p、q必定存在于二叉树中，所以继续迭代，必定变成下面两种情况
2、左右子树都返回非空节点，即匹配p、q成功，则当前节点即为公共祖先
3、左右子树返回一为空另一不为空，即已经匹配到q或q，继续迭代至完成，如情况持续，则说明p、q存在【先祖 - 子孙】关系

```java
class Solution {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        if (root == null || root == p || root == q) return root;
        TreeNode left = lowestCommonAncestor(root.left, p, q);
        TreeNode right = lowestCommonAncestor(root.right, p, q);
        if (left == null) return right;
        if (right == null) return left;
        return root;
    }
}
```
