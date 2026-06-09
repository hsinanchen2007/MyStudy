### 解题思路
此处撰写解题思路

### 代码

```golang

var maps = map[byte][]string{
	'2': {"a", "b", "c"},
	'3': {"d", "e", "f"},
	'4': {"g", "h", "i"},
	'5': {"j", "k", "l"},
	'6': {"m", "n", "o"},
	'7': {"p", "q", "r", "s"},
	'8': {"t", "u", "v"},
	'9': {"w", "x", "y", "z"},
}

func letterCombinations(digits string) []string  {
	var result []string
	if digits == ""{
		return result
	}
	result = append(result, "")
	for i:=0;i<len(digits) ;i++ {
		nums := maps[digits[i]]
		pre := result
		result = []string{}
		for _,v := range pre{
			for _,num :=range nums {
				result = append(result,v+num)
			}
		}
	}
	return result
}
```