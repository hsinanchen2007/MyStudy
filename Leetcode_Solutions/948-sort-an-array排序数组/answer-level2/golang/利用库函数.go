### 解题思路
图省事可以直接用golang的库函数。

### 代码

```golang
import "sort"
func sortArray(nums []int) []int {
    sort.Ints(nums)
    return nums
}
```