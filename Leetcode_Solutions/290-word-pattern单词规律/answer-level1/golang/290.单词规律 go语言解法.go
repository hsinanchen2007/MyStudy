### 解题思路

运用哈希表，将pattern的每个字母作为key，str的每个单词作为value，循环map判断，如果当前key已经存在，则比较value是否为str中当前单词，若不是，返回false，若当前key不存在，则把当前key和value加入进map。循环结束后返回true。

**注意**：为了避免  abba [dog dog dog dog] 这种情况返回true，我们需要同时把两个string反过来再比较一遍，若都为true，则返回true。

### 代码

```golang
func wordPattern(pattern string, str string) bool {
	ss := strings.Split(str," ")
	ps := strings.Split(pattern,"")
	if len(ss) != len(ps) {
		return false
	}
	return isMatch(ps,ss) && isMatch(ss,ps)

}
func isMatch(s1,s2 []string) bool {
	m := make(map[string]string)
	for i := 0;i < len(s1);i++ {
		if value,ok := m[s1[i]];ok{
			if value != s2[i] {
				return false
			}
		}else {
			m[s1[i]] = s2[i]
		}
	}
	return true
}
```