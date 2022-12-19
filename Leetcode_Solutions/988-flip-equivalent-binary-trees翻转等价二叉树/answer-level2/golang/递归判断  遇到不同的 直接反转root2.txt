### 解题思路
递归判断  遇到不同的 直接反转root2
之后在对比 左右节点是否都一致 

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
func flipEquiv(root1 *TreeNode, root2 *TreeNode) bool {
    // 都是空
    if root1 == nil && root2 == nil {
        return true
    }
    // 其中一个为空 或者 值不相等
    if root1 == nil || root2==nil || root1.Val != root2.Val {
        return false
    }
    // 左边不一样就换
    if root1.Left !=nil && root2.Left != nil && root1.Left.Val != root2.Left.Val ||
    root1.Left == nil && root2.Left != nil || root1.Right == nil && root2.Right != nil {
        root2.Right, root2.Left = root2.Left, root2.Right
    }
    return flipEquiv(root1.Left, root2.Left) && flipEquiv(root1.Right, root2.Right)
}
```