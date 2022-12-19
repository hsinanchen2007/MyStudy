### 解题思路
此处撰写解题思路

### 代码

```golang
func longestPalindrome(s string) int {
	res := make([]int, 52)
	for _, letter := range s{
		if 'a' <= letter && letter <= 'z' {
			res[letter-'a']++
		} else {
			res[letter-'A'+26]++
		}
	}

	ret := 0
	for _, num := range res {
		if num % 2 == 0 {
			ret += num
		} else {
			ret += num-1
		}
	}
	if ret < len(s) {
		return ret+1
	} else {
		return ret
	}
}
```