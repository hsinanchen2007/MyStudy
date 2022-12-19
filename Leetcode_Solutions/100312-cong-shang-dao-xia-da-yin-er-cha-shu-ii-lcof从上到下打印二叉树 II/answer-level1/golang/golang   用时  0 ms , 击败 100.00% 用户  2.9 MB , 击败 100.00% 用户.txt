### 解题思路
标准层序遍历，无话可说

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
func levelOrder(root *TreeNode) [][]int {
    var res [][]int
    if root == nil {
        return res
    }
    var arr []*TreeNode
    arr = append(arr, root)

    for len(arr) > 0 {
        var tmp []int
        length := len(arr)
        for i := 0; i < length; i++ {
            node := arr[0]
            tmp = append(tmp, node.Val)
            if node.Left != nil {
                arr = append(arr, node.Left)
            }
            if node.Right != nil {
                arr = append(arr, node.Right)
            }
            arr = arr[1:]
        }
        
        res = append(res, tmp)
    }
    return res
}


```