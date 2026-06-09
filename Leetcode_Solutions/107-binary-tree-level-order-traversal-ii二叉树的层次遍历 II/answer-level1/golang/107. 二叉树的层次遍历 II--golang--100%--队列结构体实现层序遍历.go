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

type Queue struct {
    front int
    rear int
    list []*TreeNode
}

func NewQueue() *Queue {
    q := new(Queue)
    q.front = 0
    q.rear = 0
    q.list = make([]*TreeNode,0)
    return q
}

func (q *Queue) Push(i *TreeNode) {
    q.list = append(q.list,i)
    q.rear++
}

func (q *Queue) Pop() *TreeNode{
    if q.front != q.rear {
        res := q.list[q.front]
        q.front++
        return res
    }
    return nil
}

 
func levelOrderBottom(root *TreeNode) [][]int {
    res := make([][]int,0)
    q := NewQueue()
    p := root
    q.Push(p)

    for q.front != q.rear {
        t := make([]int,0)
        for n := q.rear-q.front;n>0;n-- {
            k := q.Pop()
            if k != nil {
                t = append(t,k.Val)
                q.Push(k.Left)
                q.Push(k.Right)  
            }
        }
        if len(t) > 0 {
            res = append(res,t)
        }
    }

    res = Reverse(res)
    return res
}

func Reverse(t [][]int) [][]int{
    res := make([][]int,len(t))
    j := 0
    for i:=len(t)-1;i>=0;i-- {
        res[j] = t[i]
        j++
    }
    return res
}
```