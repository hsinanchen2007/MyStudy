### 解题思路
此处撰写解题思路

### 代码

```golang
func longestPalindrome(s string) int {
	ms := make(map[string]int,len(s))

	for i:=0;i<len(s);i++ {
		ms[string(s[i])] ++
	}

	var n int
	for _,v :=range ms {
		n += v/2 * 2
	}

	if n != len(s){
		return n+1
	}

	return n
}
```