### 解题思路
无

### 代码

```golang

func massage(nums []int) int {
    max := func(a, b int) int {
        if a >= b { return a }
        return b
    }
    
    pre, cur, n := 0, 0, len(nums)

    for i := 0; i < n; i++ {
        pre, cur = cur, max(cur, pre+nums[i])
    }
    
    return cur
}
```