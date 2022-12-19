### 解题思路
此处撰写解题思路

### 代码

```golang

func letterCombinations(digits string) []string {
	charMap := map[string][]string{
		"2": []string{"a", "b", "c"},
		"3": []string{"d", "e", "f"},
		"4": []string{"g", "h", "i"},
		"5": []string{"j", "k", "l"},
		"6": []string{"m", "n", "o"},
		"7": []string{"p", "q", "r", "s"},
		"8": []string{"t", "u", "v"},
		"9": []string{"w", "x", "y", "z"},
	}
	if len(digits) == 0 {
		return []string{}
	} else if len(digits) == 1 {
		return charMap[digits]
	}else if len(digits) == 2 {
		aList := charMap[string(digits[0])]
		bList := charMap[string(digits[1])]
		rlt := []string{}
		for _, va := range aList {
			for _, vb := range bList {
				rlt = append(rlt, va+vb)
			}
		}
		return rlt
	} else {
		firstChar := string(digits[0])
		result := []string{}
		for _, v := range letterCombinations(string(digits[1:])) {
			for _, ch := range charMap[firstChar] {
				result = append(result, ch+v)
			}
		}
		return result
	}
}
```