### 解题思路
此处撰写解题思路
go中序遍历，遍历到第k个元素的时候结束遍历，用指针来计数和保存结果代码不是很优雅
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
func kthSmallest(root *TreeNode, k int) int {
    var res int
    var count int
    if root == nil {
        return 0
    }

    inorder(root, k, &count, &res)

    return res
}

func inorder(root *TreeNode, k int, count *int, res *int){
    if root == nil {
        return
    }
    inorder(root.Left, k, count, res)
    *count++
    if k == *count {
        *res = root.Val
        return
    }
    inorder(root.Right, k, count, res)
    return
}
```