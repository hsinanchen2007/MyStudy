思路：
1. 遍历数组统计每对多米诺出现的次数保存在map中。
2. 按照map中的统计结果，根据组合数计算公式，n对多米诺中任意取两对组合的总数=n*(n-1)/2，累加得到总组合数。
```
执行用时 :44 ms, 在所有 Go 提交中击败了100.00%的用户
内存消耗 :7.6 MB, 在所有 Go 提交中击败了100.00%的用户
```
```Go []
func numEquivDominoPairs(dominoes [][]int) int {
	dm := make(map[string]int)
	var key string
	for _, d := range dominoes {
		key = getDominoKey(d)
		if c, ok := dm[key]; ok {
			dm[key] = c + 1
		} else {
			dm[key] = 1
		}
	}
	cnt := 0
	for _, v := range dm {
		cnt += v * (v - 1) / 2
	}
	return cnt
}

func getDominoKey(d []int) string {
	if d[0] <= d[1] {
		return strconv.Itoa(d[0]) + "," + strconv.Itoa(d[1])
	}
	return strconv.Itoa(d[1]) + "," + strconv.Itoa(d[0])
}
```
[LeetCodeByGo: 更多LeetCode题库Go语言题解](https://github.com/mrandmrsbenben/LeetCodeByGo)
