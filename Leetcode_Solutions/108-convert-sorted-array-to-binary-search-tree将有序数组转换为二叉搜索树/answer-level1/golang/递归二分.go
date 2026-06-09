### 解题思路
`树` 的 `root节点`  = `数组` 二分后的 `index`
不断的进行`二分数组` 构建`root节点`就行了

### 代码
[github](https://github.com/temporaries/leetcode)

```golang
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func sortedArrayToBST(nums []int) *TreeNode {
	if len(nums) == 0 {
		return nil
	}
	return &TreeNode{nums[len(nums)/2], sortedArrayToBST(nums[:len(nums)/2]), sortedArrayToBST(nums[len(nums)/2+1:])}
}
```