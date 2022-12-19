
![image.png](https://pic.leetcode-cn.com/29e1a12ea2bf7f21c5c3ae0c26469c7ec432f2c2a269348e1a4dadaca1509dde-image.png)

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
func zigzagLevelOrder(root *TreeNode) [][]int {
  if root == nil {
		return nil
	}
	result := make([][]int, 0)
	q := make([]*TreeNode, 0)//使用数组，代替队列
	q = append(q, root)
	l2r := true
	level := 0
	for len(q) != 0 {
		result = append(result, make([]int, 0))
		length := len(q)//q := q[1:],所以此处应该先获取原始长度
		for i := 0; i < length; i++ {
			tmp := q[0]
			q = q[1:]
			if tmp.Left != nil {
				q = append(q, tmp.Left)
			}
			if tmp.Right != nil {
				q = append(q, tmp.Right)
			}
			result[level] = append(result[level], tmp.Val)
		}
		if !l2r {
			half := len(result[level]) / 2
			for i := 0; i < half; i++ {
				result[level][i], result[level][len(result[level])-1-i] = result[level][len(result[level])-1-i], result[level][i]
			}
		}
		l2r = !l2r
		level++
	}
	return result
}
```