# 思路
1. 当根节点为空时，直接返回nil；
2. 交换根结点root左右子树的链接
3. 递归的交换左子树和右子树

# 代码
```Go
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func mirrorTree(root *TreeNode) *TreeNode {
    if root == nil {
        return nil
    }
    root.Left, root.Right = root.Right, root.Left
    mirrorTree(root.Left)
    mirrorTree(root.Right)
    return root
}
```
