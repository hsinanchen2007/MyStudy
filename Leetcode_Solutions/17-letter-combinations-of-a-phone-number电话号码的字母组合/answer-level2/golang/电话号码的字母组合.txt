### 17. 电话号码的字母组合
题意：给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。

解题思路：水题，排列组合

1A 0ms 2.6M
```
func letterCombinations(digits string) []string {
	keyBoard := make(map[int][]string)
	keyBoard[2] = []string{"a","b","c"}
	keyBoard[3] = []string{"d","e","f"}
	keyBoard[4] = []string{"g","h","i"}
	keyBoard[5] = []string{"j","k","l"}
	keyBoard[6] = []string{"m","n","o"}
	keyBoard[7] = []string{"p","q","r","s"}
	keyBoard[8] = []string{"t","u","v"}
	keyBoard[9] = []string{"w","x","y","z"}
	result := make([]string,0)
	for i,v := range digits{
		if i == 0{
			result = combine([]string{""},keyBoard[int(v - '0')])
		}else{
			result = combine(result,keyBoard[int(v - '0')])
		}
	}
	return result
}

func combine(a []string,b []string)[]string{
	result := make([]string,0)
	for _,v := range a{
		for _,k := range  b{
			result = append(result,v+k)
		}
	}
	return result
}
```