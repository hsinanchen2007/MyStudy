go 语言实现
```
package p56

import (
	"sort"
)

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}


type Internal struct {
	Start int
	End int
}

func merge(its [] Internal) []Internal {
	if len(its) == 1 {
		return its
	}

	sort.Slice(its, func(i, j int) bool {
		return its[i].Start < its[j].Start
	})

	newIts := make([]Internal, 0, len(its))
	temp := its[0]
	for i:=1; i<len(its);i++ {
		if its[i].Start <= temp.End {
			temp.End = max(temp.End, its[i].End)
		}else {
			newIts = append(newIts, temp)
			temp = its[i]
		}
	}
	newIts = append(newIts, temp)

	return newIts


}
```


