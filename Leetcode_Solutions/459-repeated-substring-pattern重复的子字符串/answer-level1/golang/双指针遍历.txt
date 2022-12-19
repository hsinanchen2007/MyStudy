### 解题思路
先确定子串长度为1，判断s是否为子串的重复，如果不是，则子串长度+1，然后重新匹配。
最后如何确定是不是匹配呢？
1. 总长度是子串长度的2倍及以上，并且能整除

### 代码

```golang
func repeatedSubstringPattern(s string) bool {
	ss := []rune(s)
    total := len(ss)
	if total == 0 {
		return false
	}

	subLen := 1
	i := 1
	j := 0
	for i < total {
		if ss[i] == ss[j] {
			i++
			j = (j + 1) % subLen
		} else {
			subLen++
			i = subLen
			j = 0
		}
	}

	return total%subLen == 0 && total/subLen >= 2
}
```