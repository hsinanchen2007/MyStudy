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
func pathSum(root *TreeNode, sum int) [][]int {
    result := make([][]int,0)
	helper(root,sum, nil, &result)

    return result
}


func helper(root *TreeNode, sum int, track []int, result *[][]int) {
	if root == nil {
		return
	}
	if root.Left ==nil && root.Right == nil && root.Val == sum {
        track = append(track, root.Val)
		*result = append(*result, track)
		return
	}
	trackcopy := append([]int{}, track...)
	helper(root.Left, sum-root.Val,append(trackcopy,root.Val), result)
	helper(root.Right, sum-root.Val,append(trackcopy,root.Val), result)
}
```