### 解题思路

遍历树，用哈希表存储遍历过的元素，若找到表中元素与当前元素相加等于k，则返回true，否则将当前元素加入哈希表。

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
func findTarget(root *TreeNode, k int) bool {
	var hash = make(map[int]int)
	return find(root,k,hash)
}
func find(root *TreeNode,k int,hash map[int]int) bool {
	if root == nil {
		return false
	}
	if _,ok := hash[k - root.Val];ok {
		return true
	}
	hash[root.Val] = 1
	return find(root.Left,k,hash) || find(root.Right,k,hash)
}
```