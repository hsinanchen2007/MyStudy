### 解题思路
主要是通过int型的除法和取余运算逐个获得低位，再逐个写到高位上就可以了

另外构造32位int型最值的方法如下，取补码
> intMax = int(^uint32(0) >> 1)
> intMin = ^intMax

### 代码

```golang
func reverse(x int) int {
	const (
		intMax = int(^uint32(0) >> 1)
		intMin = ^intMax
	)
	var i int
	for x != 0 {
		i = i*10 + x%10
		x /= 10
	}

	if i < intMax && i > intMin {
		return i
	}
	return 0
}
```