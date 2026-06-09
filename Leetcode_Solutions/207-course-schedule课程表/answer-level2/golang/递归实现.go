```
func canFinish(numCourses int, prerequisites [][]int) bool {
	var (
		i          int
		visitedMap = map[int]bool{}
		reqingMap  = map[int]bool{}
		reqMap     = map[int][]int{}
	)

	for i = 0; i < len(prerequisites); i++ {
		reqMap[prerequisites[i][0]] = append(reqMap[prerequisites[i][0]], prerequisites[i][1])
	}

	for i = 0; i < numCourses; i++ {
		if !learnCourse(i, visitedMap, reqingMap, reqMap) {
			return false
		}
	}
	return true
}

func learnCourse(i int, visitedMap, reqingMap map[int]bool, reqMap map[int][]int) bool {
	if visitedMap[i] {
		return true
	}

	reqingMap[i] = true
	if _, exists := reqMap[i]; exists {
		for j := 0; j < len(reqMap[i]); j++ {
			if visitedMap[reqMap[i][j]] {
				continue
			}
			if reqingMap[reqMap[i][j]] {
				return false
			}
			if !learnCourse(reqMap[i][j], visitedMap, reqingMap, reqMap) {
				return false
			}
		}
	}
	visitedMap[i] = true
	return true
}

```
