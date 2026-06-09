### 解题思路
此处撰写解题思路

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
func mirrorTree(root *TreeNode) *TreeNode {

    if root==nil {
        return nil
    }
    newNode := &TreeNode{root.Val, nil, nil}
    newNode.Left = mirrorTree(root.Right)
    newNode.Right = mirrorTree(root.Left)
    return newNode
}

```