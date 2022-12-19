```
import (
	"container/list"
)

func findOrder(numCourses int, prerequisites [][]int) []int {
	var (
		i, j     int
		inDegree = make([]int, numCourses)
		deps     = map[int][]int{}
		result   []int
		l        = list.New()
	)

	for i = 0; i < len(prerequisites); i++ {
		inDegree[prerequisites[i][0]]++
		deps[prerequisites[i][1]] = append(deps[prerequisites[i][1]], prerequisites[i][0])
	}
	for i = 0; i < numCourses; i++ {
		if inDegree[i] == 0 {
			l.PushBack(i)
		}
	}
	for l.Len() != 0 {
		i = l.Remove(l.Front()).(int)
		result = append(result, i)
		for j = 0; j < len(deps[i]); j++ {
			inDegree[deps[i][j]]--
			if inDegree[deps[i][j]] == 0 {
				l.PushBack(deps[i][j])
			}
		}
	}

	if len(result) != numCourses {
		return []int{}
	}
	return result
}
```
