[Range](https://github.com/golang/go/wiki/Range)
```
func canFinish(numCourses int, prerequisites [][]int) bool {
	dependCoursesInfo := make(map[int][]int)
	buildDependCoursesInfo(prerequisites, dependCoursesInfo)
	return learnOneByOne(numCourses, dependCoursesInfo)
}

func learnOneByOne(numCourses int, dependCoursesInfo map[int][]int) bool {
	courseVisited := make([]bool, numCourses)
	var dfs func(currentCourse int) bool
	dfs = func(currentCourse int) bool {
		if courseVisited[currentCourse] {
			if _, ok := dependCoursesInfo[currentCourse]; ok {
				return false
			}
		}
		courseVisited[currentCourse] = true
		if nextCourses, ok := dependCoursesInfo[currentCourse]; ok {
			for _, nextCourse := range nextCourses {
				if !dfs(nextCourse) {
					return false
				}
				courseVisited[nextCourse] = false
			}
		}
		return true
	}

	for course := range dependCoursesInfo {
		courseVisited = make([]bool, numCourses)
		if !dfs(course) {
			return false
		}
	}

	return true
}

func buildDependCoursesInfo(prerequisites [][]int, dependCoursesInfo map[int][]int) {
	for _, pair := range prerequisites {
		if nextCourses, ok := dependCoursesInfo[pair[1]]; ok {
			nextCourses = append(nextCourses, pair[0])
			dependCoursesInfo[pair[1]] = nextCourses
		} else {
			dependCoursesInfo[pair[1]] = append(make([]int, 0), pair[0])
		}
	}
}
```
