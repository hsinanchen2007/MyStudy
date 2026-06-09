遍历数组，当前bit为1时跳过下一个bit，遍历至数组末尾时若倒数第二个bit为1，则为2比特字符，反之则为1比特字符。
```
执行用时 : 4 ms, 在1-bit and 2-bit Characters的Go提交中击败了98.11% 的用户
内存消耗 : 2.8 MB, 在1-bit and 2-bit Characters的Go提交中击败了19.23% 的用户
```
```Go []
func isOneBitCharacter(bits []int) bool {
	for i := 0; i < len(bits); {
		if bits[i] == 1 {
			if i == len(bits)-2 {
				return false
			}
			i += 2
		} else {
			if i == len(bits)-1 {
				return true
			}
			i++
		}
	}
	return false
}

