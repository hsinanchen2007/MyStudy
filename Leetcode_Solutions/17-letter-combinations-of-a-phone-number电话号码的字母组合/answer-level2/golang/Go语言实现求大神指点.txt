```
func letterCombinations(digits string) []string {
	var res []string

	set := map[rune]string{
		'2': "abc", '3': "def", '4': "ghi", '5': "jkl", '6': "mno",
		'7': "pqrs", '8': "tuv", '9': "wxyz",
	}
	for i, v := range digits {

		if i == 0 {
			for _, vt := range set[v] {
				res = append(res, string(vt))
			}
		} else {
			var temp = res
			res = nil
			for _, v1 := range temp {
				for _, v2 := range set[v] {
					res = append(res, v1+string(v2))
				}
			}
		}

	}
	return res
}
```