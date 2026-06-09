### 解题思路

创建一个数组做26个字母的记数器，遍历一遍字符串，若s中存在某，则计数器相应的字母数加1，同理t中为减1，最后若计数器各个元素均为0，即返回true，否则false.

### 代码

```golang
func isAnagram(s string, t string) bool {
	if len(s) != len(t) {
		return false
	}
	var counter [26]int = [26]int{}
	for i := 0;i < len(s);i++ {
		counter[s[i] - 'a']++
		counter[t[i] - 'a']--
	}
	for _,j := range counter {
		if j != 0 {
			return false
		}
	}
	return true
}
```