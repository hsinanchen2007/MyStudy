遍历第一个字符串，计算每个字符在两个字符串中出现的次数是否相等
```
func CheckPermutation(s1 string, s2 string) bool {
	if len(s1) != len(s2) {//长度不相等就返回
		return false
	}
	for i := 0; i < len(s1); i++ {
		if strings.Count(s1, string(s1[i])) != strings.Count(s2, string(s1[i])) {
			return false
		}
	}
	return true
}
```
