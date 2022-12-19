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
func kthSmallest(root *TreeNode, k int) int {
    var ret []int
    preOrder(root, &ret)
    for i := 0; i < len(ret); i++ {
        if i == k - 1 {
            return ret[i]
        }
    }
    return 0
}

func preOrder(root *TreeNode, ret *[]int) {
    if root == nil {
        return
    }
    preOrder(root.Left, ret)
    *ret = append(*ret, root.Val)
    preOrder(root.Right, ret)
}
```