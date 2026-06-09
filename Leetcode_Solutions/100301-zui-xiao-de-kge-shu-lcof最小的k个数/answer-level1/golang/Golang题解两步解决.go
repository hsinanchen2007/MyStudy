### 解题思路

第一步，排序`arr`数组  
第二步，取排序后的`arr`数组前k个数字返回

### 代码

```golang
import "sort"

type IntSlice []int

func (s IntSlice) Len() int { return len(s) }

func (s IntSlice) Swap(i, j int){ s[i], s[j] = s[j], s[i] }

func (s IntSlice) Less(i, j int) bool { return s[i] < s[j] }

func getLeastNumbers(arr []int, k int) []int {
    sort.Sort(IntSlice(arr))
    return arr[:k]
}
```