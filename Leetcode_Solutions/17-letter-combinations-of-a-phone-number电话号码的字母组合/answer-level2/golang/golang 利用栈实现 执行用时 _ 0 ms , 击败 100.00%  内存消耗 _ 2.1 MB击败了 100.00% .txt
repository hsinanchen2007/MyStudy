```go
func letterCombinations(digits string) []string {
	ret := make([]string, 0)

	if digits == ""{
		return ret
	}

	digit2LetterList := map[string][]string{
		"2": {"a", "b", "c"},
		"3": {"d", "e", "f"},
		"4": {"g", "h", "i"},
		"5": {"j", "k", "l"},
		"6": {"m", "n", "o"},
		"7": {"p", "q", "r", "s"},
		"8": {"t", "u", "v"},
		"9": {"w", "x", "y", "z"},
	}
	ret = append(ret, "")

	for i := 0; i < len(digits); i++ {
		retLen := len(ret)
		digit := digits[i : i+1]
		letterList := digit2LetterList[digit]
		for j := 0; j < retLen; j++ {
			for _, letter := range letterList {
				ret = append(ret, ret[0]+letter)
			}
			ret = ret[1:]
		}

	}

	return ret
}
```


以 "23为例" 
ret内的值为
循环之前: [""]
"2" 之后: [a, b, c]
"3" 之后: [ad, ae, af, bd, be, bf, cd, ce, cf]