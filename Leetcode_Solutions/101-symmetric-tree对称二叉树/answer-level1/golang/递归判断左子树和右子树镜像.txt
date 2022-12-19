### 解题思路
递归判断左子树和右子树镜像，直到都是叶子节点，再判断根的值是否相等

### 代码

```golang
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func isSymmetric(root *TreeNode) bool {
    if root == nil {
        return true
    }
    return helper(root.Left, root.Right)
}

func helper(left, right *TreeNode) bool {
    if left == nil && right == nil {
        return true
    }
    if left != nil && right != nil {
        return left.Val == right.Val && helper(left.Left, right.Right) && helper(left.Right, right.Left)
    }
    return false
}
```