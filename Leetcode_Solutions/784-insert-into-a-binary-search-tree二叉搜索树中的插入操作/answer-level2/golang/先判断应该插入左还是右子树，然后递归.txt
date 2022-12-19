### 解题思路
将要插入的值和跟节点值比较，如果比跟节点值小则应该插入左字树，比跟节点大则应该插入右子树。
如果左右子树为空，则添加新节点，然后递归即可。

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
func insertIntoBST(root *TreeNode, val int) *TreeNode {
    if val < root.Val {
        if root.Left == nil {
            root.Left = &TreeNode{ Val : val}
        }else{
            insertIntoBST(root.Left, val)
        }
    }else{
        if root.Right == nil {
            root.Right = &TreeNode{ Val : val}
        }else{
            insertIntoBST(root.Right, val)
        }
    }
    return root
}
```