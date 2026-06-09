### 解题思路
* 指针传递 结合 递归
* 中序遍历二叉搜索树

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

func convertBST(root *TreeNode) *TreeNode {
    sum := 0
    return changeVal(root, &sum)
}

func changeVal(root *TreeNode, sum *int) *TreeNode {
    if root == nil {
        return nil
    }
    changeVal(root.Right, sum)
    *sum = *sum + root.Val
    root.Val = *sum
    changeVal(root.Left, sum)
    return root
}
```