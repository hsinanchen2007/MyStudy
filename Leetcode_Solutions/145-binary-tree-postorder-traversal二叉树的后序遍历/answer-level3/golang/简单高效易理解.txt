```
func postorderTraversal(root *TreeNode) []int {
    res := []int{}
    p := root
    s := make([]*TreeNode, 0)
    
    pre := p
    for p != nil || len(s) > 0 {
        if p != nil {
            s = append(s, p)
            pre = p
            p = p.Left
        } else {
            // 取出栈顶元素
            top := s[len(s)-1]
            // 判断上一个节点是不是栈顶节点的Right
            // 如果是，则出栈，读取值，并将pre 指向top节点
            if pre == top.Right {
                res = append(res, top.Val)
                s = s[:len(s)-1]
                pre = top
            } else {
                pre = p
                p = top.Right
            }
        }
    }
    return res
}
```
