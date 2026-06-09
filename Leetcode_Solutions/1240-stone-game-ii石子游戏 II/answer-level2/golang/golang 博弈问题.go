博弈问题: 辗转计算对手的最佳得分，并用总得分减去对手的得分，得到我的最佳得分

具体看注释
```
func stoneGameII(piles []int) int {
	sum := 0
	for i := 0; i < len(piles); i++ {
		sum += piles[i]
	}
	hasCal := make(map[[3]int]int)
	v1 := f(piles, 0, 1, 1, sum, hasCal) // 第一次拿一颗石子
	v2 := f(piles, 0, 2, 1, sum, hasCal) // 第一次拿两颗石子
	if v1 > v2 {
		return v1
	}
	return v2
}

// idx: 从当前位置开始拿石子
// stone: 拿石子的数量
// M: 题目中的M
// sum: 当前idx开始的石子总数
// hasCal: 是否已经计算过.，如果计算过，直接返回，不需要再计算
func f(piles []int, idx, stone, M, sum int, hasCal map[[3]int]int) int {
	if v, ok := hasCal[[3]int{idx, stone, M}]; ok {
		return v
	}
	// 计算当前可以拿到的石头数
	count := 0
	for i := 0; i < stone; i++ {
		if idx+i >= len(piles) {
			return count
		}
		count += piles[idx+i]
	}

	// 题目要求：M = max(M, X)
	maxStone := max(stone, M)
	maxT := 0

	// 对手可以拿的石头的堆数，遍历找到最优解。因为双方都是最佳水平，所以对手的最优解，才是我们需要的值
	for i := 1; i <= maxStone*2; i++ {
		t := f(piles, idx+stone, i, maxStone, sum-count, hasCal)
		maxT = max(t, maxT)
	}
	hasCal[[3]int{idx, stone, M}] = sum - maxT // sum - 对手的最优解得到当前选手的解
	return sum - maxT
}

func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}

```
