### 解题思路
如果两个字符串的长度不同，那么肯定不符合条件。  
然后将第一个字符串的不同字符以及出现的次数构建成一个map，  
再遍历第二个字符串，如果出现某个未在第一个字符串中出现过的字符，或者某个字符出现的次数不同于第一个字符串，就跳出循环返回 false。  

### 代码

```golang
func isAnagram(s string, t string) bool {
	if len(s) != len(t) {
		return false
	}
	var verify = make(map[string]int)
	for i:=0;i<len(s); i++{
		if _,ok := verify[string(s[i])];ok {
			verify[string(s[i])]+=1
		}else {
			verify[string(s[i])]=1
		}
	}
	var flag = true
	for i := 0; i < len(t); i++ {
		if _, ok := verify[string(t[i])];!ok || strings.Count(t, string(t[i]))!=verify[string(t[i])]{
			flag = false
			break
		}
	}
	return flag
}

```