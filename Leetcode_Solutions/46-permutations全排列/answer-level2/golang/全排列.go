## 思路

回溯法，分为t步来填补所有的数，mp[i]来表示nums[i]是否已经被使用
使用for循环+递归实现

```golang
func expand(result *[][]int, nums, buf []int, mp []bool, t int) {
    if len(nums) == t {
        res := make([]int, t)
        copy(res, buf)
        *result = append(*result, res)
        return
    }
    for i, n := range nums {
        if mp[i] {
            continue
        }
        buf[t] = n
        mp[i] = true
        expand(result, nums, buf, mp, t+1)
        mp[i] = false
    }
}

func permute(nums []int) (result [][]int) {
    n := len(nums)
    mp := make([]bool, n)
    buf := make([]int, n)
    
    expand(&result, nums, buf, mp, 0)
    return result
}
```
