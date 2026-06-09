go版分治
```golang
func diffWaysToCompute(s string) []int {
	var optis []int
	for i := 0; i < len(s); i++ {
		if s[i] == '+' || s[i] == '-' || s[i] == '*' {
			optis = append(optis, i)
		}
	}
	if len(optis) == 0{
		return []int{conv(s)}
	}
	if len(optis) == 1 {
		i := optis[0]
		return []int{compute(s[i], s[:i], s[i+1:])}
	}
	var res []int
	for _, i := range optis{
		left, right := diffWaysToCompute(s[:i]), diffWaysToCompute(s[i+1:])
		//  两边结果组合运算
		for _, v1 := range left{
			for _, v2 := range right{
				res = append(res, computei(s[i], v1, v2))
			}
		}
	}
	return  res
}

func compute(way byte, left, right string) int {
	res, l, r := 0, conv(left), conv(right)
	switch way {
	case '+':
		res = l + r
	case '-':
		res = l - r
	case '*':
		res = l * r
	}
	return res
}

func computei(way byte, l, r int) int {
	var res int
	switch way {
	case '+':
		res = l + r
	case '-':
		res = l - r
	case '*':
		res = l * r
	}
	return res
}

func conv(s string) int {
	var total int
	b := []byte(s)
	for i, ch := range b{
		ch -= '0'
		total += int(ch)*int(math.Pow10(len(b)-i-1))
	}
	return total
}

```
