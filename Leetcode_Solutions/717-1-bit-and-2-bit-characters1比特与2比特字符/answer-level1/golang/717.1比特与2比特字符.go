### 解题思路

线性扫描，遇见1就+2，遇见0就+1，看指针最后能否落在最后一个0上面，若能则返回true，否则false。

### 代码

```golang
func isOneBitCharacter(bits []int) bool {
	i := 0
	for i < len(bits) - 1 {
		i += bits[i] + 1
	}
	return i == len(bits) - 1
}

```