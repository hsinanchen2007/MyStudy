这种方法用来解210 不太合适，所以我又看了别人的Topology sorting

```
func canFinish(numCourses int, prerequisites [][]int) bool {
    preMap := map[int][]int{}
    for _, p := range prerequisites {
        if courses, ok := preMap[p[0]]; ok {
            preMap[p[0]] = append(courses, p[1])
        } else {
            preMap[p[0]] = []int{p[1]}
        }
    }
    for len(preMap) > 0 {
        anyCource := getAnyKey(preMap)
        needLearn := map[int]bool{anyCource: true}
        if !backtracing(preMap, anyCource, needLearn) {return false}
    }
    return true
}

func backtracing(preMap map[int][]int, course int, needLearn map[int]bool) bool {
    if _, ok := preMap[course]; !ok {return true}
    for _, c := range preMap[course] {
        if _, ok := needLearn[c]; !ok {
            needLearn[c] = true
            if !backtracing(preMap, c, needLearn) {return false}
            delete(needLearn, c)
        } else {
            return false
        }
    }
    delete(preMap, course)
    return true
}

func getAnyKey(preMap map[int][]int) int {
    var result int
    for k := range preMap {
        result = k
        break
    }
    return result    
}
```
