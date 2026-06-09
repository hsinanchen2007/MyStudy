```
import "container/list"

// Kahn’s Algorithm
// https://www.educative.io/edpresso/what-is-topological-sort
func canFinish(numCourses int, prerequisites [][]int) bool {
	var (
		i, v       int
		inDegree   = make([]int, numCourses)
		reqMap     = map[int][]int{}
		visitedMap = map[int]bool{}
		l          = list.New()
	)

	// 要想学课程 [0] 必须先学课程 [1]
	for i = 0; i < len(prerequisites); i++ {
		// 所以课程 [1] 的入度为 0
		inDegree[prerequisites[i][0]]++
		reqMap[prerequisites[i][1]] = append(reqMap[prerequisites[i][1]], prerequisites[i][0])
	}
	for i = 0; i < numCourses; i++ {
		if inDegree[i] == 0 {
			l.PushBack(i)
		}
	}

	for l.Len() != 0 {
		v = l.Remove(l.Front()).(int)
		visitedMap[v] = true
		for i = 0; i < len(reqMap[v]); i++ {
			inDegree[reqMap[v][i]]--
			if inDegree[reqMap[v][i]] == 0 {
				l.PushBack(reqMap[v][i])
			}
		}
	}

	return len(visitedMap) == numCourses
}

```
