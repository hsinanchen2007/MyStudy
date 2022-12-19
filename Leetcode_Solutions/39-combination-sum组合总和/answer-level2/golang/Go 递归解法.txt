思路：将target的值依次减去数组元素并递归调用直到target的值小于或等于数组各元素，由于数组元素可重复使用，但重复组合不计在内，所以递归调用时只包含当前元素及之后的所有元素即可。

```
执行用时 :4 ms, 在所有 Go 提交中击败了96.76%的用户
内存消耗 :4.6 MB, 在所有 Go 提交中击败了36.36%的用户
```
```Go []
func combinationSum(candidates []int, target int) [][]int {
	comb := [][]int{}
	for i := range candidates {
		if candidates[i] == target {
			comb = append(comb, []int{candidates[i]})
		} else if candidates[i] < target {
			rtn := combinationSum(candidates[i:], target-candidates[i])
			for j := range rtn {
				if len(rtn[j]) == 0 {
					continue
				}
				comb = append(comb, append([]int{candidates[i]}, rtn[j]...))
			}
		}
	}
	return comb
}
```
[LeetCodeByGo: 更多LeetCode题库Go语言题解](https://github.com/mrandmrsbenben/LeetCodeByGo)