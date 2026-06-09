
![image.png](https://pic.leetcode-cn.com/f83a2868486d47dc80e60230e4506432e55ed99e542d5bf8242f0e33e69f8994-image.png)

```
func Sum(cur *TreeNode, sum int, pathsum []int) int {
    if cur == nil {
        return 0
    }
    cnt := 0
    curpathsum := []int{}
    pathsum = append(pathsum, 0)    // 考虑自己
    for _,x := range pathsum {      // 到当前节点为止的所有路径和
        if x + cur.Val == sum {     // 累计到当前节点为止的所有等于 sum 的路径和
            cnt++
        }
        curpathsum = append(curpathsum, x+cur.Val)  // 更新路径和
    }
    return cnt + Sum(cur.Left, sum, curpathsum) + Sum(cur.Right, sum, curpathsum)
}

func pathSum(root *TreeNode, sum int) int {
    return Sum(root, sum, []int{})
}
```