```
func levelOrder(root *TreeNode) [][]int {
    res := make([][]int, 0)
    if root == nil {
        return res
    }
    // 创建一个队列来放每一层的元素
    help := []*TreeNode{root}
    for len(help) != 0 {
        helpLen := len(help)
        tmp := make([]int, 0)
        for i := 0; i < helpLen; i++ {
            tmp = append(tmp, help[i].Val)
            if help[i].Left != nil {
                help = append(help, help[i].Left)
            }
            if help[i].Right != nil {
                help = append(help, help[i].Right)
            }
        }
        // 每一层元素的值都会放在一个tmp里面
        if len(tmp) != 0 {
            res = append(res, tmp)
        }
        // 把已经处理过的元素去掉，也就是改变队列的长度
        help = help[helpLen:]
    }
    return res
}
```
