### 解题思路

Java 双百两行递归
记录一下，难得做的这么快，就写一次题解把。
根据二叉搜索树的特点来思考，若一大一小则分布在当前节点两侧；否则，在同侧，那么对下一级节点进行判断

### 代码
```java []
class Solution {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        if (root.val == p.val || root.val == q.val || root.val > p.val && root.val < q.val || root.val < p.val && root.val > q.val) return root;
        return (root.val < p.val)?lowestCommonAncestor(root.right, p, q): lowestCommonAncestor(root.left, p, q);
    }
}
```
