## 递归

```go
func isSymmetric(root *TreeNode) bool {
    if root == nil {
        return true
    }
    return TestLR(root.Left, root.Right)
}
func TestLR(l, r *TreeNode) bool {
    if l == nil && r == nil {
        return true
    } else if l == nil || r == nil {
        return false
    } else if l.Val != r.Val {
        return false
    } else {
        return TestLR(l.Left, r.Right) && TestLR(l.Right, r.Left)
    }
}
```
## 迭代

```go
func isSymmetric(root *TreeNode) bool {
    if root == nil {
        return true
    }
    queue := []*TreeNode{root}
    for len(queue) > 0  {
        end := len(queue)
        for i,j := 0, end-1; i<j; i, j = i+1, j-1 {
            if queue[i] == nil && queue[j] == nil {
                continue
            } else if queue[i] == nil || queue[j] == nil {
                return false
            } else if queue[i].Val != queue[j].Val {
                return false
            } 
        }
        for i := 0; i < end; i++ {
            if queue[i] != nil {
                queue = append(queue, queue[i].Left, queue[i].Right)
            }
        }
        queue = queue[end:]
    }
    return true
}
```