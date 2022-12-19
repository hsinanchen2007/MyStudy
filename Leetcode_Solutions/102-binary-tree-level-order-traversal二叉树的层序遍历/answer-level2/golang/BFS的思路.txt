### 解题思路
BFS的思路

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

	list := list.New()
	list.PushFront(root)

	for list.Len() > 0 {
		var currLevelNode []int
		length := list.Len()

		for i := 0; i < length; i++ {
			node := list.Remove(list.Front()).(*TreeNode)
			currLevelNode = append(currLevelNode,node.Val)
			if node.Left != nil {
				list.PushBack(node.Left)
			}
			if node.Right != nil {
				list.PushBack(node.Right)
			}
		}
		res = append(res,currLevelNode)
	}
	return res
}
```