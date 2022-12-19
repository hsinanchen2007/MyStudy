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
func buildTree(preorder []int, inorder []int) *TreeNode {
    if len(preorder) == 0 {
        return nil
    }
    root := &TreeNode{
        Val: preorder[0],
    }
    index := findIndex(inorder, preorder[0])
    leftNums, rightNums := len(inorder[:index]), len(inorder[index+1:])
    root.Left = buildTree(preorder[1:leftNums+1], inorder[:index])
    root.Right = buildTree(preorder[leftNums+1:rightNums+leftNums+1], inorder[index+1:])
    return root
}

func findIndex(nums []int, value int) int{
    for i, v := range nums {
        if v == value {
            return i
        }
    }
    return -1
}
```