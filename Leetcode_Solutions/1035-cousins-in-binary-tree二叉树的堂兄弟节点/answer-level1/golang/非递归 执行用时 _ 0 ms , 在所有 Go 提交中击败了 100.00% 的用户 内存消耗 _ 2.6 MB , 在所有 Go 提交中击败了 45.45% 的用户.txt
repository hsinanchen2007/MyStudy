### 解题思路

很容易想到层次遍历，难点是想到索引占位和最后的是否父节点

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
func isCousins(root *TreeNode, x int, y int) bool {
if root == nil || x == y {
		return false
	}

	var queue []*TreeNode
	queue = append(queue, root)
	deep := 1

	for len(queue) > 0 {
		qLen := len(queue)
		xIdx := -1
		yIdx := -1
		for i := 0; i < qLen; i++ {
			node := queue[i]
			if node != nil {
				if node.Val == x {
					xIdx = i
				}
				if node.Val == y {
					yIdx = i
				}
				queue = append(queue, node.Left)
				queue = append(queue, node.Right)
			}
		}

		if xIdx != -1 && yIdx != -1 {
			cha := math.Abs(float64(xIdx - yIdx))
			if cha > 1 {
				return true
			}

			//小的索引是奇数，返回true
			if cha == 1 {
				min := 0
				if xIdx > yIdx {
					min = yIdx
				} else {
					min = xIdx
				}

				if min%2 != 0 {
					return true
				}
			}
            return  false
		}
		deep++
		queue = queue[qLen:]
	}

	return false
}
```