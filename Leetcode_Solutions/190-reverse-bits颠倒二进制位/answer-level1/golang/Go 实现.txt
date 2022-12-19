1. 数值转字符串
2. 逆序循环颠倒字符串
3. 补足32位
4. 字符串转数值
```
执行用时 : 4 ms, 在Reverse Bits的Go提交中击败了93.23% 的用户
内存消耗 : 2.7 MB, 在Reverse Bits的Go提交中击败了10.00% 的用户
```
```Go []
func reverseBits(num uint32) uint32 {
	str := strconv.FormatUint(uint64(num), 2)
	rev := ""
	for i := len(str) - 1; i >= 0; i-- {
		rev = rev + str[i:i+1]
	}
	if len(rev) < 32 {
		rev = rev + strings.Repeat("0", 32-len(rev))
	}
	n, _ := strconv.ParseUint(rev, 2, 64)
	return uint32(n)
}