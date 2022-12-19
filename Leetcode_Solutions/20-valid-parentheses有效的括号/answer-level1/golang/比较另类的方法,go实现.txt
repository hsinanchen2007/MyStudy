![image.png](https://pic.leetcode-cn.com/e60105e3541a2248311d22e6f02af1accf2b4c65eef4346a9f95610088f10a3c-image.png)

剔除常见错误
删除正确子表达式再检查错误。
```
func isValid(s string) bool {
	//数量不对
	if len(s)%2 != 0 {
		return false
	}

	//开闭数量不等
	m := map[string]string{"(": ")", "[": "]", "{": "}"}
	for k, v := range m {
		if strings.Count(s, k) != strings.Count(s, v) {
			return false
		}
	}

	//删除有效
	isvalid := []string{"()", "[]", "{}"}
	for {
		contain := false
		for _, v := range isvalid {
			if s == "" {
				return true
			}
			contain = strings.Contains(s, v)
			s = strings.Replace(s, v, "", -1)
		}
		if !contain {
			break
		}
	}

	//匹配常见无效
	notValid := []string{"(}", "(]", "{)", "{]", "[)", "[}"}
	for _, v := range notValid {
		if strings.Contains(s, v) {
			return false
		}
	}

	return true
}
```
