import "sort"
func twoCitySchedCost(costs [][]int) int {
	sums := 0
	l := []int{}
	for _, item := range costs {
		sums += item[0]
		l = append(l, item[0]-item[1])
	}
	sort.Ints(l)
	for _, x := range l[len(l)/2:] {
		sums = sums - x
	}
	return sums
}