## 题解思路：
1. 如果p, q 分别位于左，右子树，则根即为要找的节点
2. 如果p, q 都位于左子树，则公共祖先由左子树中产生。反之则从右子树中产生

根据这个特点，可以写出以下递归代码：
```go
func lowestCommonAncestor(root, p, q *TreeNode) *TreeNode {
    if root == p || root == q || root == nil {
        return root
    }
    left := lowestCommonAncestor(root.Left, p, q)
    right := lowestCommonAncestor(root.Right, p, q)
    if left == nil{
        return right
    }else if right == nil{
        return left
    }else{
        return root
    }
}
```
时间复杂度 O(N)