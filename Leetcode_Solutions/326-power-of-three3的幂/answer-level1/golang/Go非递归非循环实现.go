将整数n转换为3进制字符串，判断是否第一位为1其他位为0，符合条件则为3的幂。
```
执行用时 : 12 ms, 在Power of Three的Go提交中击败了100.00% 的用户
内存消耗 : 6.1 MB, 在Power of Three的Go提交中击败了15.09% 的用户
```
```Go []
func isPowerOfThree(n int) bool {
	if n < 1 {
		return false
	}
	s := strconv.FormatInt(int64(n), 3)
	return s[0:1] == "1" && strings.Count(s, "0") == len(s)-1
}