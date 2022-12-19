### 解题思路

利用哈希表求解，然后设置一个`bool`变量`rem`指明是否还存在剩余的字符，每次遍历时，都要将每个字符出现的次数按照2的倍数减掉，然后
判断`rem`，若为真，则加1否则不加

### 代码

```golang

func longestPalindrome(s string) int {
	m := make(map[byte]int)
	for _, v := range s {
		m[byte(v)]++
	}

	res := 0
	rem := false
	for _, v := range m {
		if v%2 != 0 {
			rem = true
		} 
			res += (v >> 1) << 1
		
	}
	if rem {
		return res + 1
	} else {
		return res
	}
}
```