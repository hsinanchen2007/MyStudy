### 解题思路

根据题意，如5二进制为101，则补数等于111-101=010，根据这个，可用与所给二进制数长度相等的各位全为1的二进制数减之，即为补数。

### 代码

```golang
func findComplement(num int) int {
	var tmp int = 1
	for num >= tmp {
		tmp <<= 1
	}
	return tmp - 1 - num
}
```