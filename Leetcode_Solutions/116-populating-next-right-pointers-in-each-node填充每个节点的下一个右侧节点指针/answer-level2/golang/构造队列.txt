```
type Queue struct{
    data []*Node
}

func (q *Queue) Enqueue(node *Node){
    q.data = append(q.data,node)
}

func (q *Queue) Dequeue() (node *Node){
    node = q.data[0]
    q.data = q.data[1:]
    return node
}

func (q *Queue) Peek() (node *Node){
    return q.data[0]
}

func (q *Queue) isEmpty() bool{
    return len(q.data) == 0
}

func (q *Queue) size() int{
    return len(q.data)
}

func connect(root *Node) *Node {
	if root == nil{
        return nil
    }
    q := Queue{}
    q.Enqueue(root)
    for !q.isEmpty(){
        size := q.size()
        for i := 0; i < size; i++{
            cur := q.Dequeue()
            if(i < size-1){
                cur.Next = q.Peek()
            }
            if cur.Left!=nil{
                q.Enqueue(cur.Left)
            }
            if cur.Right!=nil{
                q.Enqueue(cur.Right)
            }
        }
    }
    return root
}
```
