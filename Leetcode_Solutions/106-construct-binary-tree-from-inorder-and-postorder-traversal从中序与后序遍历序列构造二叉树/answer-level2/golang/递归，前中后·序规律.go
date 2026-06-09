### 解题思路
规律题，理解前序，中序，后序遍历的规律，手速一把梭

以 `后序遍历 root (index=length-1)` 寻找 `中序遍历 root (index=k)`

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
func buildTree(inorder []int, postorder []int) *TreeNode {
	l := len(postorder)-1
	for k := range inorder {
		if inorder[k] == postorder[l] {
			return &TreeNode{
				Val:   inorder[k],
				Left:  buildTree(inorder[:k], postorder[:k]),
				Right: buildTree(inorder[k+1:], postorder[k:l]),
			}
		}
	}
	return nil
}
```

