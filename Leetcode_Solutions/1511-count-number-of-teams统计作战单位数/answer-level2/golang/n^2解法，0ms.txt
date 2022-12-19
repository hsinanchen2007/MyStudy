统计位置i，左边大于和小于的个数，右边大于和小于的个数，然后组合


```
func numTeams(rating []int) int {
	res := 0
	leftMax, leftMin := make([]int, len(rating)), make([]int, len(rating))
	rightMax, rightMin := make([]int, len(rating)), make([]int, len(rating))
	for i, v := range rating {
		cntMax, cntMin := 0, 0
		for j := 0; j < i; j++ {
			if rating[j] > v {
				cntMax++
			}
			if rating[j] < v {
				cntMin++
			}
		}
		leftMax[i] = cntMax
		leftMin[i] = cntMin
		cntMax, cntMin = 0, 0
		for j := i + 1; j < len(rating); j++ {
			if rating[j] > v {
				cntMax++
			}
			if rating[j] < v {
				cntMin++
			}
		}
		rightMax[i] = cntMax
		rightMin[i] = cntMin
	}
	for i := 0; i < len(rating); i++ {
		res += leftMax[i]*rightMin[i] + leftMin[i]*rightMax[i]
	}
	return res
}
```
