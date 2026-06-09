### 解题思路
层序遍历

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
func levelOrder(root *TreeNode) []int {
    var res []int
    if root == nil {
        return res
    }

    var arr []*TreeNode
    arr = append(arr, root)

    for len(arr) > 0 {
        length := len(arr)
        for i := 0; i < length; i++ {
            node := arr[0]
            if node.Left != nil {
                arr = append(arr, node.Left)
            }
            if node.Right != nil {
                arr = append(arr, node.Right)
            }
            res = append(res, node.Val)
            arr = arr[1:]
        }
    }
    return res
}
```