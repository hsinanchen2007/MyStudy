### 解题思路
此处撰写解题思路

### 代码

```golang
func climbStairs(n int) int {
    m := make([]int,n+1)
    return cs(0,n,m)
}

func cs(i,n int,m []int)int{
    if i> n {
        return 0
    }
    if i == n {
        return 1
    }
    if m[i] >0 {
        return m[i]
    }
    m[i] = cs(i+1,n,m)+cs(i+2,n,m)
    return m[i]
}
```