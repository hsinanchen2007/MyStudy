### 解题思路
此处撰写解题思路

### 代码

```golang
func verifyPostorder(postorder []int) bool {
    n := len(postorder)
    if n<2 {
        return true
    }
    root := postorder[n-1]
    cur := 0
    for cur<n && postorder[cur]<root {
        cur++
    }
    for i := cur; i<n; i++ {
        if postorder[i]<root {
            return false
        }
    } 
    return verifyPostorder(postorder[:cur]) && verifyPostorder(postorder[cur:n-1])
}
```