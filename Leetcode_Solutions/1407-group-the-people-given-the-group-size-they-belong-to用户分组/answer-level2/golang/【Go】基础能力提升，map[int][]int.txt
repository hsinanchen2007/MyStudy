部门出游，出去分房间，两个队，单身的一队，通铺的一队，-_-||，还有通铺？！
```
func groupThePeople(groupSizes []int) [][]int {
	groups := make(map[int][]int)
	for id, group := range groupSizes {
		groups[group] = append(groups[group], id)
	}

	groupsCount := 0
	for group, ids := range groups {
		groupsCount += len(ids) / group
	}

	result := make([][]int, groupsCount)
	index := 0
	for group, ids := range groups {
		for _, id := range ids {
			if len(result[index]) == group {
				index++
			}
			result[index] = append(result[index], id)
		}
		index++
	}
	return result
}
```
