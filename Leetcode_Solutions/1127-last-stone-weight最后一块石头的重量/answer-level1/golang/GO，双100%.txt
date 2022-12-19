func lastStoneWeight(stones []int) int {
	l := len(stones)
	if l == 0 {
		return 0
	}
	sort.Ints(stones)
	for i := l-1; i > 0; i-- {
		if stones[i] == stones[i-1] {
			stones[i-1] = 0
			continue
		}
		stones[i-1] = int(math.Abs(float64(stones[i] - stones[i-1])))
	}
	return stones[0]
}

遍历当前的数组，先排序，然后取最后的两个数据进行计算，并把差值放在倒数第二位作为下次计算的最后一个，然后重新排序后继续计算

0ms，2MB  打败100%的同学
