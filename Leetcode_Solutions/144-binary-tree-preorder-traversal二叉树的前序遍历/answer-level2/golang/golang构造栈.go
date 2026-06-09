```
//构造栈
type Stack struct{
    data []*TreeNode
}

func (s *Stack)push(cur *TreeNode){
    s.data = append(s.data,cur)
}

func (s *Stack)pop()(cur *TreeNode){
    len := len(s.data)
    cur = s.data[len-1]
    s.data = s.data[:len-1]
    return cur
}

func (s *Stack)isEmpty() bool{
    return len(s.data)==0
}

func NewStack()(s Stack){
    s.data = []*TreeNode{}
    return s
}


func preorderTraversal(root *TreeNode) []int {
    res := []int{}
    cur := root
    if root==nil{
        return res
    }

    s := NewStack()
    s.push(cur)
    for !s.isEmpty(){
        cur = s.pop()
        res = append(res,cur.Val)
        if cur.Right!=nil{
            s.push(cur.Right)
        }
        if cur.Left!= nil{
            s.push(cur.Left)
        }
    }
    return res
}
```
