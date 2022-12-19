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
var cache []int
func kthLargest(root *TreeNode, k int) int {
    // 中序遍历然后顺序输出结果，再从最后选择第k个
    inorder(root)
    if k > len(cache) {
        return 0
    }
    // 逆序选择第K个
    var res int
    for i := len(cache) - 1; i >= 0; i-- {
        if i == len(cache) - k {
            res = cache[i]
        }
    }
    return res
}

func inorder(root *TreeNode) {
    if root == nil {
        return
    }
    inorder(root.Left)
    cache = append(cache, root.Val)
    inorder(root.Right)
}
```