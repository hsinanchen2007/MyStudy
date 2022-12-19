### 解题思路
排序

### 代码

```golang
func frequencySort(s string) string {
	cntMap := make(map[rune]int)
	for _, c := range s {
		cntMap[c]++
	}
	alphCnt := make(afs, 0, len(cntMap))
	for c, v := range cntMap {
		alphCnt = append(alphCnt, AlphaFeq{
			val: c,
			cnt: v,
		})
	}
	sort.Sort(&alphCnt)
	runes := make([]rune, 0, len(s))
	for _, af := range alphCnt {
		for i := 0; i < af.cnt; i++ {
			runes = append(runes, af.val)
		}
	}
	return string(runes)
}

type AlphaFeq struct {
	val rune
	cnt int
}
type afs []AlphaFeq

func (af *afs) Len() int {
	return len(*af)
}

func (af *afs) Less(i, j int) bool {
	return (*af)[i].cnt > (*af)[j].cnt
}

func (af *afs) Swap(i, j int) {
	(*af)[i], (*af)[j] = (*af)[j], (*af)[i]
}
```