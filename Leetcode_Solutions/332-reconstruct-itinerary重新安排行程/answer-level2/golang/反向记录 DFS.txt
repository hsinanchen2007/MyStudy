参考别人的思路：

```
import (
	"container/list"
	"sort"
	"strings"
)

func findItinerary(tickets [][]string) (rst []string) {
	var (
		i       int
		curr    string
		length  = len(tickets)
		ticket  []string
		stack   = list.New()
		graph   = make(map[string][]string, 0)
		outgree = make(map[string]int)
	)
	sort.Slice(tickets, func(i, j int) bool {
		if tickets[i][0] == tickets[j][0] {
			return strings.Compare(tickets[i][1], tickets[j][1]) < 0
		} else {
			return strings.Compare(tickets[i][0], tickets[j][0]) < 0
		}
	})
	for i = 0; i < length; i++ {
		ticket = tickets[i]
		outgree[ticket[0]]++
		graph[ticket[0]] = append(graph[ticket[0]], ticket[1])
	}

	stack.PushBack("JFK")
	for stack.Len() != 0 {
		curr = stack.Back().Value.(string)
		if outgree[curr] == 0 {
			stack.Remove(stack.Back())
			rst = append(rst, curr)
		} else {
			stack.PushBack(graph[curr][0])
			graph[curr] = graph[curr][1:]
			outgree[curr]--
		}
	}

	for i = 0; i < len(rst)/2; i++ {
		rst[i], rst[len(rst)-1-i] = rst[len(rst)-1-i], rst[i]
	}
	return
}
```
