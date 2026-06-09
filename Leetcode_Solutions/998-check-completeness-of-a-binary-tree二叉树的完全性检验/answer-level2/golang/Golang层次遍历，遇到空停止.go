## 思路
1. 层次遍历，借助一个队列q
2. 遍历时遇到nil结点，结束遍历
3. 检查q剩下的部分，如果有非nil的，就肯定不是完全二叉树

在层次遍历时，也可以使用一个标记表示是否遇到空值，遇到空值后就不能再有非空值。但是个人觉得不如分两步遍历清晰。

```go
func isCompleteTree(root *TreeNode) bool {
        q := []*TreeNode{}
        q = append(q, root)
        
        for len(q) > 0 && q[0] != nil {
                q = append(q, q[0].Left, q[0].Right)
                q = q[1:]
        }
        
        for _, v := range q {
                if v != nil {
                        return false
                }
        }
        
        return true
}
```
