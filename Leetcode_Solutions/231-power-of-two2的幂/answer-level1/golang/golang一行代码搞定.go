n如果是2的幂, 二进制下最高位为1, 其余全是0; n-1要么等于0, 要么二进制下都是1; n&(n-1)必为0

```
func isPowerOfTwo(n int) bool {
	return n > 0 && n&(n-1) == 0
}
```

也可以写成

```
func isPowerOfTwo(n int) bool {
	return n != 0 && n&(n-1) == 0
}
```

