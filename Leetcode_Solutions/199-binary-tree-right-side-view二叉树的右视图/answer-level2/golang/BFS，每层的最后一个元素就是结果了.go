```
import (
	"container/list"
)

func rightSideView(root *TreeNode) (rst []int) {
	if root == nil {
		return
	}
	var (
		i, nextLevelCount int
		currLevelCount    = 1
		queue             = list.New()
		node              *TreeNode
	)
	queue.PushBack(root)

	for queue.Len() != 0 {
		for i = 0; i < currLevelCount; i++ {
			node = queue.Remove(queue.Front()).(*TreeNode)
			if node.Left != nil {
				queue.PushBack(node.Left)
				nextLevelCount++
			}
			if node.Right != nil {
				queue.PushBack(node.Right)
				nextLevelCount++
			}

			if i == currLevelCount-1 {
				rst = append(rst, node.Val)
			}
		}
		currLevelCount = nextLevelCount
		nextLevelCount = 0
	}

	return
}
```
