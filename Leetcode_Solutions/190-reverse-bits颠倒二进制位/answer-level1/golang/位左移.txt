
### 代码

```golang
func reverseBits(num uint32) uint32 {
    var res uint32
	for i := 0; i < 32;i++ {
		cur := num & 1  // 拿到最低位的值
		res = res + (cur << uint32(31 - i))
		num = num >> 1
	}
	return res
}
```