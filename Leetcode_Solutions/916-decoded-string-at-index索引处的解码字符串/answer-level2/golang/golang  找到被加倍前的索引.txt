计算字符串S截止到当前idx的长度。找到加倍前的索引

eg： S = ab2c3de4 K = 10
![image.png](https://pic.leetcode-cn.com/faa3de77fe2604e8031ca6b2921316c241d37e8cb13a98dfc7c36a51bb422e34-image.png)
1. 当idx = 4, s[idx] = '3', oldcount = 5 newcount = 15，15 > 10， 此时的新字符串是 ab2c * 3, 那么我们也可以把K按照'ab2c'的长度分段。最后一段的长度就是在ab2c中的索引，所以我们只要计算decodeAtIndex(ab2c, newk)即可，依此类推。
2. 如果我们发现当前长度大于等于k，并且没有被数字加倍，那么我们可以直接返回当前所以的字符。
3. 如果当前长度等于k，且最后一个字符是字母，直接返回最后一个字符
```
func decodeAtIndex(S string, K int) string {
	count := 0
	for i := 0; i < len(S); i++ {
		c1 := 0
		if isAlpha(S[i]) {
			c1 = count + 1
		} else {
			c1 = count * int(S[i] - '0')
		}
		if c1 == K && isAlpha(S[i]) {
			return string(S[i])
		}
		if c1 >= K {
			if c1 == i + 1 && isAlpha(S[i]) {
				return string(S[K-1])
			}
			K = K % count
			if K == 0 {
				K = count
			}
			return decodeAtIndex(S[:i], K) // 计算被加倍前的那一段
		}
		count = c1
	}
	return ""
}

func isAlpha(s byte) bool {
	if s >= 'a' && s <= 'z' {
		return true
	}
	return false
}

```
