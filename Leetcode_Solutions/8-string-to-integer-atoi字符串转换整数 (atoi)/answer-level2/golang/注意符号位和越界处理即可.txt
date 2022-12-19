### 解题思路
此处撰写解题思路

### 代码

```golang
func myAtoi(str string) int {
	if len(str) == 0{
		return  0
	}
	bFindFirst := false
	number, flag := 0,1
	for _, s := range str{
		switch s {
		case ' ':
			if bFindFirst{
				goto FlagRes
			}
		case '+':
			if bFindFirst{
				goto FlagRes
			}else{
				bFindFirst = true
			}
		case '-':
			if bFindFirst{
				goto FlagRes
			}else{
				bFindFirst = true
				flag = -1
			}
		case '0','1','2','3','4','5','6','7','8','9':
			bFindFirst = true
			number = number*10 + int(s - '0')
			if number * flag > math.MaxInt32{
				return math.MaxInt32
			}
			if number * flag < math.MinInt32{
				return math.MinInt32
			}
		default:
			goto FlagRes
		}
	}
FlagRes:
	res := number *flag
	return res
}
```