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

 // NewQueueList is used to
func NewQueueList() *list.List {

	return list.New()
}

// Push is used to
func Push(queue *list.List, value interface{}) {

	queue.PushBack(value)
}

// Pop is used to
func Pop(queue *list.List) interface{} {

	e := queue.Front()
	return queue.Remove(e)
}

func levelOrder(root *TreeNode) [][]int {

    if root == nil {
        return nil
    }
    ret := [][]int{}
    queue := NewQueueList()
    Push(queue, root)
    length := queue.Len()
    for queue.Len() > 0 {
        subRet := []int{}
        for i:=0; i<length; i++ {
            e := Pop(queue).(*TreeNode)
            subRet = append(subRet, e.Val)
            if e.Left != nil {
                Push(queue, e.Left)
            }
            if e.Right != nil {
                Push(queue, e.Right)
            }
        }
        ret = append(ret, subRet)
        length = queue.Len()
    }
    return ret
}
```