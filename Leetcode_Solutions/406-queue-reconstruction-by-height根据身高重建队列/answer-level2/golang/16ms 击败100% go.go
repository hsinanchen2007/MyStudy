```golang
func reconstructQueue(people [][]int) [][]int {
	sort.Slice(people, func(i, j int) bool {
		if people[i][0] == people[j][0] {
			return people[i][1] < people[j][1]
		}

		return people[i][0] > people[j][0]
	})

	res := make([][]int, 0)

	for i := 0; i < len(people); i++ {
		p := people[i][1]
		if p >= len(res) {
			res = append(res, people[i])
		} else {
			res = append(res, res[len(res)-1])
			copy(res[p+1:], res[p:])
			res[p] = people[i]
		}
	}

	return res
}
```
