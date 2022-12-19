```
func isCousins(root *TreeNode, x int, y int) bool {
    if root == nil || x == y {
        return false
    }

    var queue []*TreeNode
    queue = append(queue, root)

    for {
        size := len(queue)
        cnt, empty, last := 0, 0, -1

        for i := 0; i < size; i++ {
            if queue[i] == nil {
                empty++
                continue
            }
            if queue[i].Val == x || queue[i].Val == y {
                cnt++
                if last < 0 {
                    last = i
                } else if i-last > 1 || i%2 == 0 { //find it
                    return true
                } else { //have same parent
                    return false
                }
            }
            queue = append(queue, queue[i].Left)
            queue = append(queue, queue[i].Right)
        }
        //search over
        if empty == size {
            break
        }
        //at least in different depth
        if cnt == 1 {
            return false
        }

        queue = queue[size:]
    }

    return false
}
```
