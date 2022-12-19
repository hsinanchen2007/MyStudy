## 结果

![image.png](https://pic.leetcode-cn.com/5899fb4aa3958c14e898c6f5c47e400d050b5a1e88f5bf63702da2cc286d5235-image.png)

## 思路

回溯法，开始前将数组排序，每一步填一个数，填完以后如果之后的数与当前填数相同则跳过，避免重复

## Code

```
func permuteUnique(nums []int) (result [][]int) {
    sort.Ints(nums)
    mp := make([]bool, len(nums))
    fill(nums, mp, []int{}, &result, make(map[string]bool))
    return
}

func fill(nums []int, mp []bool, buf []int, result *[][]int, dict map[string]bool) {
    n := len(nums)
    if n == len(buf) {
        cp := make([]int, len(buf))
        copy(cp, buf)
        *result = append(*result, cp)
        return
    }
    for i:=0;i<n;i++ {
        if mp[i] {
            continue
        }
        mp[i] = true
        v := nums[i]
        fill(nums, mp, append(buf, v), result, dict)
        mp[i] = false
        // 去重
        for i+1<n && nums[i+1] == v {
            i++
        }
    }
    
}
```

