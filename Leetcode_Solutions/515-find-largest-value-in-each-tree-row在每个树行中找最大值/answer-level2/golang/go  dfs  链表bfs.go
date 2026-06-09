### 解题思路

俩种解法 

bfs 用的链表  
下面还有个ListNode 实现的简易队列

### 代码
bfs
```golang

// bfs
import "container/list"
const INT_MIN =^int(^uint(0) >> 1)
func largestValues(root *TreeNode) []int {
    if root == nil {
        return nil
    }
    q := list.New()
    var res []int
    q.PushBack(root)
    for q.Len() > 0 {
        lvMax := INT_MIN
        count := q.Len()
        for count > 0 {
            count--
            node := q.Front().Value.(*TreeNode)
            lvMax = max(lvMax, node.Val)
            q.Remove(q.Front())
            if node.Left != nil {
                q.PushBack(node.Left)
            }
            if node.Right != nil {
                q.PushBack(node.Right)
            }
        }
        res = append(res, lvMax)
    }

    return res
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}
```

下面是dfs
```golang
// dfs
const INT_MIN =^int(^uint(0) >> 1)
func largestValues(root *TreeNode) []int {

    var helper func(root *TreeNode, level int)
    var res []int 
    helper = func(root *TreeNode, level int) {
        if root == nil {
            return
        }
        if level >= len(res) {
            res = append(res, INT_MIN)
        }
        res[level] = max(res[level], root.Val)
        helper(root.Left, 1+level)
        helper(root.Right, 1+level)
    }
    helper(root,0)
    return res
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}

```

### 解题思路

bfs 借助链表实现
弄个list存树的节点
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

type ListNode struct {
    Val *TreeNode
    Next *ListNode
}
type queue struct{
    Len int
    Head *ListNode
    Tail *ListNode
}
const INT_MIN =^int(^uint(0) >> 1)

func newQueue() queue {
    tail := &ListNode{}
    head := tail
    return queue{ Len: 0, Head: head, Tail: tail }
}
func (q *queue)push(v *TreeNode) {
    node := &ListNode{Val : v}
    q.Len++
    q.Tail.Next = node
    q.Tail = q.Tail.Next
}
func (q *queue)pop() *TreeNode {
    node := q.Head.Next.Val
    q.Head = q.Head.Next
    q.Len--
    return node
}

// bfs
func largestValues(root *TreeNode) []int {
    if root == nil {
        return nil
    }
    q := newQueue()
    var res []int
    q.push(root)
    for q.Len > 0 {
        lvMax := INT_MIN
        count := q.Len
        for count > 0 {
            count--
            node := q.pop()
            lvMax = max(lvMax, node.Val)
            if node.Left != nil {
                q.push(node.Left)
            }
            if node.Right != nil {
                q.push(node.Right)
            }
        }
        res = append(res, lvMax)
    }

    return res
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}
```