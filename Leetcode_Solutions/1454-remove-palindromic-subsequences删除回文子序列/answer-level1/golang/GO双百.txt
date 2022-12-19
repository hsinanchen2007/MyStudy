删除子序列，不是删除子串，因此看到题的时候多多少少会懵一下

```golang
func removePalindromeSub(s string) int {
	if len(s)==0{
		return 0
	}
	i,j:=0,len(s)-1
	for i<j{
		if s[i]!=s[j]{
			return 2
		}
		i++
		j--
	}
	return 1
}
```