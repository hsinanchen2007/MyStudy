```
import (
	"container/list"

)

func zigzagLevelOrder(root *TreeNode) (rst [][]int) {
	if root == nil {
		return nil
	}

	var (
		e              *list.Element
		n              *TreeNode
		l              = list.New()
		level          = 1
		currLevelCount = 1
		nextLevelCount = 0
	)
	l.PushBack(root)

	for l.Len() != 0 {
		var tmpRst = make([]int, currLevelCount)
		nextLevelCount = 0
		for i := 0; i < currLevelCount; i++ {
			e = l.Front()
			l.Remove(e)
			n = e.Value.(*TreeNode)
			if level%2 == 1 {
				tmpRst[i] = n.Val
			} else {
				tmpRst[currLevelCount-1-i] = n.Val
			}
			if n.Left != nil {
				l.PushBack(n.Left)
				nextLevelCount++
			}
			if n.Right != nil {
				l.PushBack(n.Right)
				nextLevelCount++
			}
		}
		level++
		rst = append(rst, tmpRst)
		currLevelCount = nextLevelCount
	}

	return
}

```
