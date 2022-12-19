## 解题思路
因为二叉搜索树的特性，p,q 都小于根，则最近公共祖先肯定位于左子树；反之如果都大于根，最近公共祖先肯定位于右子树。
如果p,q 一个大于，一个小于根，或者p,q任一等于根，则根即为最近公共祖先。

```go
 func lowestCommonAncestor(root, p, q *TreeNode) *TreeNode {
    if root == p || root == q || root == nil {
        return root
    }
    if root.Val > p.Val && root.Val > q.Val{
        return lowestCommonAncestor(root.Left, p, q)
    }else if root.Val < p.Val && root.Val < q.Val {
        return lowestCommonAncestor(root.Right, p, q)
    }else{
        return root
    }
}
```
