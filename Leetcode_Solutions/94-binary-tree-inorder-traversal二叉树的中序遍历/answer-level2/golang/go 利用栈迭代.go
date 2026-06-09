### 解题思路
此处撰写解题思路
利用一个栈暂存root，优先打印left

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
 
type (
    Node struct {
        Val  *TreeNode
        next *Node
    }

    stackL struct {
        S    *Node
        topS int
    }
)

func NewStackL() *stackL {
    s := stackL{&Node{nil , nil}, 0}
    return &s
}
func (s *stackL) StackEmpty() bool {
    if s.topS == 0 {
        return true
    }
    return false
}

func (s *stackL) Push(x *TreeNode) error {
    cur := &Node{x, s.S}
    s.S = cur
    s.topS++
    return nil
}
func (s *stackL) Pop() (*TreeNode, error) {
    if s.StackEmpty() {
        return nil, fmt.Errorf("underflow")
    } else {
        s.topS--
        cur := s.S
        s.S = s.S.next
        return cur.Val, nil
    }
}

func inorderTraversal(root *TreeNode) []int {
    res := []int{}
    stack := NewStackL()
    cur := root
    for cur != nil || !stack.StackEmpty(){
        for cur != nil {
            stack.Push(cur)
            cur = cur.Left
        }
        cur, _= stack.Pop()
        res = append(res, cur.Val)
        cur = cur.Right
    }
    
    return res
}



```