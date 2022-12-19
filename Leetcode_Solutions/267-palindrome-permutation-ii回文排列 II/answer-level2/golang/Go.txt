### 解题思路
此处撰写解题思路

### 代码

```golang
func generatePalindromes(s string) []string {
	l := len(s)
	isOdd := true	// 长度是否为奇数
	odd := ""
	if l % 2 == 0 {
		isOdd = false
	}

	m := make(map[byte]int)
	for i:=0;i<l;i++ {
		m[s[i]]++
	}

	oneNum := 0
	var oddByte byte
	for k, v := range m {
		if v % 2 == 1 {
			if isOdd { // 奇数
				oneNum++
				if oneNum > 1 {
					return []string{}
				}
				oddByte = k
			}else {
				return []string{}
			}
		}
	}

	if isOdd {
		m[oddByte]--
		odd = fmt.Sprintf("%c", oddByte)
	}

	list := make([]string, 0, 4)
	dfsFindPalindromes(m, odd, &list, l)

	return list
}

func dfsFindPalindromes(m map[byte]int, result string, resultList *[]string, l int) {
	if len(result) == l {
		*resultList = append(*resultList, result)
	}

	for k, v := range m {
		if v < 2 {
			continue
		}

		m[k]-=2

		result := fmt.Sprintf("%c%s%c",k, result, k)
		dfsFindPalindromes(m, result, resultList, l)
		m[k]+=2	// 回溯
	}
}
```