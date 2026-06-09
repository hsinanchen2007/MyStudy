### 解题思路
此处撰写解题思路
官方题解一
### 代码

```golang
import "sort"
func minIncrementForUnique(A []int) int {
    res := 0
    cnt := make([]int, 80000)
    repeat := make([]int, 0)
    for i := 0; i < len(A); i++ {
        cnt[A[i]]++
        if cnt[A[i]] > 1 {
            repeat = append(repeat, A[i])
        }
    }
    sort.Ints(repeat)
    for i := 0; i < len(cnt) && len(repeat) > 0; i++ {
        if cnt[i] == 0 {
            if repeat[0] < i {
                res += i - repeat[0]
                repeat = repeat[1 : ]
            }
        }
    }
    return res
}
```