```
import (
	"sort"
	"strconv"
	"strings"
)

func largestNumber(nums []int) string {
	var numStrs = make([]string, len(nums))
	var i int
	for i = 0; i < len(nums); i++ {
		numStrs[i] = strconv.Itoa(nums[i])
	}
	sort.Slice(numStrs, func(i, j int) bool {
		return comp(numStrs[i]+numStrs[j], numStrs[j]+numStrs[i])
	})

	return strip(strings.Join(numStrs, ""))
}

func comp(a, b string) bool {
	for i := 0; i < len(a); i++ {
		if a[i] != b[i] {
			return a[i] > b[i]
		}
	}
	return false
}

func strip(n string) string {
	var i int
	for i = 0; i < len(n); i++ {
		if n[i] != '0' {
			break
		}
	}
	if i == len(n) {
		return "0"
	}
	return n[i:]
}
```
