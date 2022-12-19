```
import (
	"container/list"
	"sort"
)

func eventualSafeNodes(graph [][]int) (rst []int) {
	var (
		i, j         int
		length       = len(graph)
		outdegree    = make([]int, length)
		revertsGraph = make([][]int, length)
		l            = list.New()
	)

	for i = 0; i < length; i++ {
		outdegree[i] = len(graph[i])
		for j = 0; j < len(graph[i]); j++ {
			revertsGraph[graph[i][j]] = append(revertsGraph[graph[i][j]], i)
		}
	}
	for i = 0; i < length; i++ {
		if outdegree[i] == 0 {
			l.PushBack(i)
		}
	}

	for l.Len() != 0 {
		i = l.Remove(l.Front()).(int)
		rst = append(rst, i)
		for j = 0; j < len(revertsGraph[i]); j++ {
			outdegree[revertsGraph[i][j]]--
			if outdegree[revertsGraph[i][j]] == 0 {
				l.PushBack(revertsGraph[i][j])
			}
		}
	}

	sort.Ints(rst)
	return
}
```
