```
type Queue struct {
    list []*TreeNode
}

func NewQueue() *Queue {
    list := make([]*TreeNode, 0)
    return &Queue{list}
}

func (q *Queue) Put(nd *TreeNode) {
    q.list = append(q.list, nd)
}

func (q *Queue) Get() *TreeNode {
    if q.Len() == 0 {
        return nil
    }
    nd := q.list[0]
    q.list = q.list[1:]
    return nd
}

func (q *Queue) Len() int {
    return len(q.list)
}

func maxLevelSum(root *TreeNode) (max int) {
    if root == nil {
        return
    }
    maxVal, maxLevel, curLevel := root.Val, 1, 1
    queue := NewQueue()
    queue.Put(root)
    for queue.Len() != 0 {
        size, tmp := queue.Len(), 0
        fmt.Println(queue)
        for size != 0 {
            nd := queue.Get()
            if nd.Left != nil {
                queue.Put(nd.Left)
            }
            if nd.Right != nil {
                queue.Put(nd.Right)
            }
            size --
            tmp += nd.Val
        }
        if tmp > maxVal {
            maxVal = tmp
            maxLevel = curLevel
        }
        curLevel++
    }
    max = maxLevel
    return
}
```
