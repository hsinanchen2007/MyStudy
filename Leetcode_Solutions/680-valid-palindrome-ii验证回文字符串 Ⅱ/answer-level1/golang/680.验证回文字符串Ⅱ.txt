### 解题思路

掐头去尾，找到i开头j结尾但s[i] != s[j]的字串，判断i+1到j的字串或i到j-1的字串是否为回文串即可。

### 代码

```golang
func validPalindrome(s string) bool {
	if len(s) <= 2 {
		return true
	}
	i,j := 0,len(s) - 1
	for i < j {
		if s[i] != s[j] {
			break
		}
		i++
		j--
	}
	return valid(s,i + 1,j) || valid(s,i,j - 1)
}
func valid(s string,i int,j int) bool {
	for i < j {
		if s[i] != s[j] {
			return false
		}
		i++
		j--
	}
	return true
}
```