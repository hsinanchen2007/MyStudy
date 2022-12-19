### 解题思路
此处撰写解题思路

### 代码

```golang
func longestPalindrome(s string) int {
	ms := make([]int,128)
	var n int

	for i:=0;i<len(s);i++ {
		ms[s[i]] ++

		if ms[s[i]] >= 2 {
			n += 2
			ms[s[i]] -= 2
		}
	}

	if n != len(s){
		return n+1
	}

	return n
}
```