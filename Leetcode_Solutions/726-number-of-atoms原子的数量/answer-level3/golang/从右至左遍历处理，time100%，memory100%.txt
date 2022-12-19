原帖：[https://leetcode.com/problems/number-of-atoms/discuss/319807/Runtime%3A-0-ms-faster-than-100.00-of-Go]()

```
func countOfAtoms(formula string) string {
	var maps = make(map[string]int)
	var multiple []int
	str, count := "", ""
	for i := len(formula) - 1; i >= 0; i-- {
		char := formula[i]
		if char >= '0' && char <= '9' {
			count = string(char) + count
		} else {
			if char == ')' {
				cnt, _ := strconv.Atoi(count)
				if len(multiple) > 0 {
					cnt = cnt * multiple[len(multiple)-1]
				}
				multiple = append(multiple, cnt)
				count = ""
			} else if char == '(' {
				multiple = multiple[:len(multiple)-1]
			} else if char >= 'a' && char <= 'z' {
				str = string(char) + str
			} else if char >= 'A' && char <= 'Z' {
				str = string(char) + str
				var num int
				if count == "" {
					count = "1"
				}
				cnt, _ := strconv.Atoi(count)
				if len(multiple) > 0 {
					num = multiple[len(multiple)-1] * cnt
				} else {
					num = cnt
				}
				maps[str] += num
				str = ""
				count = ""
			}
		}
	}
	result := ""
	var keys []string
	for k := range maps {
		keys = append(keys, k)
	}
	sort.Strings(keys)
	for _, k := range keys {
		v := maps[k]
		result += k
		if v != 1 {
			result += strconv.Itoa(v)
		}
	}
	return result
}
```
