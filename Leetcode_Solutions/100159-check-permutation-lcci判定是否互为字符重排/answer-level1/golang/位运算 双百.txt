
1. 判断长度，长度一致继续往下判断
2. 通过位运算判断两个字符串包含的元素是否相同
3. 通过异或运算判断两个字符串元素是否对称

代码如下：
```golang
func CheckPermutation(s1 string, s2 string) bool {
	var (
		result = 0
		bit1   = uint(0)
		bit2   = uint(0)
	)

	if len(s1) != len(s2) {
		return false
	}

	for i := 0; i < len(s1); i++ {
		result = result ^ int(s1[i]) ^ int(s2[i])

		c1 := uint(s1[i] - 'a')
		bit1 = bit1 | (1 << c1)

		c2 := uint(s2[i] - 'a')
		bit2 = bit2 | (1 << c2)
	}

	//fmt.Println(result, bit1, bit2)

	return result == 0 && bit1 == bit2
}
```



