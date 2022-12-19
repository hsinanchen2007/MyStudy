时间复杂度 o(n),空间复杂度 o(n)

```golang
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func minDepth(root *TreeNode) int {
   if root == nil {
		return 0
	}
	q := make([]*TreeNode, 0)//用slice代替队列
	q = append(q, root)
	level := 0
	for len(q) != 0 {
		curLength := len(q) //q = q[1:],所以此处应该先获取原始长度
		for i := 0; i < curLength; i++ {
			tmp := q[0]
			q = q[1:]
			if tmp.Left == nil && tmp.Right == nil {//第一个叶子节点的深度，即为最小深度
				return level + 1
			}
			if tmp.Left != nil {
				l := tmp.Left
				q = append(q, l)
			}
			if tmp.Right != nil {
				r := tmp.Right
				q = append(q, r)
			}
		}
		level++
	}
	return 0
}
```