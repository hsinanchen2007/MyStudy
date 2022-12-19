### 解题思路
此处撰写解题思路

### 代码

```golang

func reverseWords(s []byte) {
	n := len(s)
	for i, j := 0, n-1; i < j; i, j = i+1, j-1 {
		s[i], s[j] = s[j], s[i]
	}
	start := 0
	for i := 0; i < n; i++ {
		if s[i] == ' ' {
			for m, n := start, i-1; m < n; m, n = m+1, n-1 {
				s[m], s[n] = s[n], s[m]
			}
			start = i + 1
		}
	}

	for i, j := start, n-1; i < j; i, j = i+1, j-1 {
		s[i], s[j] = s[j], s[i]
	}
}

```