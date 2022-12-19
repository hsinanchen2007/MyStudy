### 解题思路
进行后序遍历，最后返回的是根点
先左子树
后右子树
然后左右交换

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

    if root == nil {
        return root
    }
    l:=mirrorTree(root.Left)
    r:=mirrorTree(root.Right)
    return &TreeNode{Left:r,Right:l,Val:root.Val}

}
```