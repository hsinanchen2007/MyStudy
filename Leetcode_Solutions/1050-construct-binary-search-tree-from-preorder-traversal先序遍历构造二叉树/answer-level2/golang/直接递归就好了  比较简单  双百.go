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
func bstFromPreorder(preorder []int) *TreeNode {
	l := len(preorder)
	if l == 0{
		return nil
	}
	idx := l
	rootVal := preorder[0]
	for i:=1;i<l;i++{
		if preorder[i]>rootVal{
			idx = i
			break
		}
	}
	return &TreeNode{
		Val:rootVal,
		Left:bstFromPreorder(preorder[1:idx]),
		Right:bstFromPreorder(preorder[idx:]),
	}
}
```