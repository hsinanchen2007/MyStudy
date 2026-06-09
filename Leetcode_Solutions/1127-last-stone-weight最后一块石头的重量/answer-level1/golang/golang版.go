func lastStoneWeight(stones []int) int {
	x := len(stones)
	if x == 1 {
		return stones[0]
	}
	if x == 0 {
		return 0
	}
	sort.Ints(stones)
	stonesnew := stones[0 : x-2]
	if stones[x-2] > stones[x-1] {
		stonesnew = append(stonesnew, stones[x-2]-stones[x-1])
	} else {
		stonesnew = append(stonesnew, stones[x-1]-stones[x-2])
	}
	y := lastStoneWeight(stonesnew)
	return y
}