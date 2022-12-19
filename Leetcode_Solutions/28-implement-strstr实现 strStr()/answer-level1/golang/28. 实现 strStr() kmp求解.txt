### 解题思路
此处撰写解题思路

### 代码

```golang
// func strStr(haystack string, needle string) int {

// }
// GetNextArray is used to 获取字符串中每一个字符，前面字符串的最大前后缀相同部分
func GetNextArray(str string) []int {

	length := len(str)
	if length == 0 {
		return []int{}
	}
	if length == 1 {
		return []int{-1}
	}
	if length == 2 {
		return []int{-1, 0}
	}
	ret := []int{-1, 0}
	cn := 0
	for i := 2; i < length; i++ {
		cn = ret[i-1]
		for {
			if str[cn] == str[i-1] {
				ret = append(ret, cn+1)
				break
			} else {
				cn = ret[cn]
			}
			if cn < 0 {
				ret = append(ret, 0)
				break
			}
		}
	}
	return ret
}

// strStr is used to 如果str2是str1的字串，返回str2在str1中的起始位置，否则返回-1
func strStr(str1, str2 string) int {
    if len(str2)==0 {
        return 0
    }
	if len(str1) == 0 || len(str1) < len(str2) {
		return -1
	}
	next := GetNextArray(str2)
	i := 0
	j := 0
	for i < len(str1) && j < len(str2) {
		if str1[i] == str2[j] {
			i++
			j++
		} else if next[j] == -1 {
			i++
		} else {
			j = next[j]
		}
	}
	if j == len(str2) {
		return i - j
	} else {
		return -1
	}
}
```