### 代码

```golang
import (
	"sort"
	"strconv"
)

type ans []string

func (self ans) Len() int {
	return len(self)
}

func (self ans) Swap(i, j int) {
	t := self[i]
	self[i] = self[j]
	self[j] = t
}

func (self ans) Less(i, j int) bool {
	a, _ := strconv.Atoi(self[i] + self[j])
	b, _ := strconv.Atoi(self[j] + self[i])
	return a < b
}

func minNumber(nums []int) string {
	var a ans
	a = make([]string, len(nums))
	for i, v := range nums {
		a[i] = strconv.Itoa(v)
	}
	sort.Sort(a)
	res := ""
	for _, v := range a {
		res += v
	}
	return res
}
```