```
func groupAnagrams(strs []string) (rst [][]string) {
	var alphaMap = map[string][]string{}

	for i := 0; i < len(strs); i++ {
		alpha := getAlpha(strs[i])
		ary := alphaMap[alpha]
		alphaMap[alpha] = append(ary, strs[i])
	}

	for _, v := range alphaMap {
		rst = append(rst, v)
	}
	return
}

var alphas = "0123456789#"

func getAlpha(str string) (rst string) {
	alphaMap := map[uint8]int{}
	for i := 0; i < len(str); i++ {
		alphaMap[str[i]-'a']++
	}
	rstBytes := []byte{}
	for i := 0; i < 26; i++ {
		if alphaMap[uint8(i)] != 0 {
			rstBytes = append(rstBytes, alphas[0]+uint8(alphaMap[uint8(i)]))
		} else {
			rstBytes = append(rstBytes, alphas[10])
		}
	}

	return string(rstBytes)
}
```
