```
func myAtoi(str string) int {
	clean := func(s string)(sign int,  ss string) {
		s = strings.TrimSpace(s)
		if len(s) == 0{
			return 0,s
		}
		switch s[0]{
		case '0', '1', '2', '3', '4', '5', '6', '7', '8', '9':
			sign,ss = 1,s
		case '+':
			sign,ss = 1,s[1:]
		case '-':
			sign,ss = -1,s[1:]
		default:
			sign,ss = 0,""
		}
		for i,b := range ss{
			if b < '0' || '9' < b {
				ss = ss[:i]
				break
			}
		}
		return
	}
	convert := func(sign int ,ss string)int {
		num := 0
		for _,v := range ss{
			num = num * 10 + int(v - '0')
			switch  {
			case sign == 1 && num > math.MaxInt32:
				return math.MaxInt32
			case sign == -1 && num *sign < math.MinInt32:
				return math.MinInt32
			}
		}
		return sign*num
	}
	return convert( clean(str))
}

```
