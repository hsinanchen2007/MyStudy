### 解题思路
先前序遍历将树转化为数组，然后求第几大的值即转化为求数组下标为len(arr) - k

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

func toArray(root *TreeNode) []int {
    var ret []int
    if root == nil {
        return ret
    }
    ret = append(ret, toArray(root.Left)...)
    ret = append(ret, root.Val)
    ret = append(ret, toArray(root.Right)...)
    return ret
}

func kthLargest(root *TreeNode, k int) int {
    if root == nil {
        return -1
    }
    arr := toArray(root)
    return arr[len(arr) - k]
}
```