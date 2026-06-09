1.深度优先搜索
 ```
//dfs
func levelOrder(root *TreeNode) [][]int {
    if root == nil {
        return [][]int{}
    }

    res := [][]int{}
    dfs(root, 0, &res)
    return res
}

func dfs(root *TreeNode, level int, res *[][]int) {
    //terminator
    if root == nil {
        return
    }

    //process logic of current level
    if len(*res) <= level {
        *res = append(*res, []int{root.Val})
    } else {
        (*res)[level] = append((*res)[level], root.Val)
    }

    //drill down
    dfs(root.Left, level+1, res)
    dfs(root.Right, level+1, res)
}
```
2.广度优先搜索
```
func levelOrder(root *TreeNode) [][]int {
    if root == nil {
        return [][]int{}
    }
    res := [][]int{}
    queue := []*TreeNode{root}
    for len(queue) != 0 {
        tmp := []int{}
        lengthQ := len(queue)
        for i := 0; i < lengthQ; i++ {
            tmp = append(tmp, queue[i].Val)
        }
        res = append(res, tmp)
        for i := 0; i < lengthQ; i++ {
            if queue[i].Left != nil {
                queue = append(queue, queue[i].Left)
            }
            if queue[i].Right != nil {
                queue = append(queue, queue[i].Right)
            }
        }
        queue = queue[lengthQ:]
    }

    return res    
}
```

