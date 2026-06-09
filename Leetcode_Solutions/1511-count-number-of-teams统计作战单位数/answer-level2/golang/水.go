### 解题思路
记录一下后面比前面大的下标和个数就能过

### 代码

```golang
type large struct {
	max   int
	flags []int
}

func numTeams(rating []int) int {
	larges, mins := make([]large, len(rating)), make([]large, len(rating))
	for i := range rating {
		for j := i + 1; j < len(rating); j++ {
			if rating[j] > rating[i] {
				larges[i].max++
				larges[i].flags = append(larges[i].flags, j)
			}
		}
	}
	for i := len(rating) - 1; i > -1; i-- {
		for j := i - 1; j > -1; j-- {
			if rating[j] > rating[i] {
				mins[i].max++
				mins[i].flags = append(mins[i].flags, j)
			}
		}
	}
	return getResult(larges) + getResult(mins)
}

func getResult(data []large) int {
	res := 0
	for i := range data {
		for _, j := range data[i].flags {
			res += data[j].max
		}
	}
	return res
}

```