双指针需要注意一下边界条件
```
func bagOfTokensScore(tokens []int, p int) int {
	sort.Ints(tokens)
	if len(tokens) == 0 || p < tokens[0] {
		return 0
	}
	var score, ret, i int
	j := len(tokens) - 1
	for i <= j {
		for i < len(tokens) && p >= tokens[i] {
			score++
			p -= tokens[i]
			i++
			if ret < score {
				ret = score
			}
		}
		if score > 0 && i <= j {
			p += tokens[j]
			j--
			score--
		}
	}
	return ret
}
```
