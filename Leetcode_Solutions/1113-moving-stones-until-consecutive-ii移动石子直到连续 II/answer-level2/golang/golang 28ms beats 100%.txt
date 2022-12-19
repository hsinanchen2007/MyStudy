### 解题思路：
首先排序
- 最大值，计算中间相邻的数的差 + 两边相邻数的差的较大者
- 最小值
  1. 遍历数组，找到最小的 `j`， 使得 `stones[j] - stones[i] + 1 >= len(stones)`, 说明所有数字可以放在者两个数中间，计算其中的空位，和 `min` 比较。
   1. 如果 `stones[j] - stones[i] + 1 < len(stones)`, 那么就需要移动 `len(stones) - (j - i + 1)` 次
   1.  特别的，`[3,4,5, 10]`， 这种无法移动其中一个端点，需要特殊处理
### 代码：
```go [-Go]


func numMovesStonesII(stones []int) []int {
	sort.Ints(stones)
	max := 0
	min := 2 << 31
	for i := 1; i < len(stones); i++ {
		max += (stones[i] - stones[i-1] - 1)
	}
	if max == 0 {
		return []int{0, 0}
	}
	if max - (stones[1] - stones[0] - 1) == 0 || max - (stones[len(stones)-1] - stones[len(stones)-2] - 1) == 0 {
		if max - (stones[1] - stones[0] - 1) == 0 {
			min = Min(2, stones[1] - stones[0] - 1)
		} else {
			min = Min(2, stones[len(stones)-1] - stones[len(stones)-2] - 1)
		}
		return []int{min, max}
	}
	max -= Min(stones[1] - stones[0] - 1, stones[len(stones)-1] - stones[len(stones)-2] - 1)
	for i := 0; i < len(stones); i++ {
		for j := i + 1; j < len(stones); j++ {
			if stones[j] - stones[i] + 1 >= len(stones) {
				min = Min(min, stones[j] - stones[i] - 1 - (j - i - 1))
				break
			} else {
				min = Min(min, len(stones) - (j - i + 1))
			}
		}
	}
	min = Min(min, len(stones) - 1)
	return []int{min, max}
}

func Min(x, y int) int {
	if x < y {
		return x
	}
	return y
}
```