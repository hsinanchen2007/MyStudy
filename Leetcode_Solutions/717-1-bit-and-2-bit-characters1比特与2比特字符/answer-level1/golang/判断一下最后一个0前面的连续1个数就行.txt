### 解题思路
判断一下最后一个0前面的连续1个数就行

### 代码

```golang
func isOneBitCharacter(bits []int) bool {
	if len(bits) <= 1 {
		return true
	}
	counter := 0
	for i := len(bits) - 2; i > -1; i-- {
		if bits[i] == 0 {
			break
		}
		counter++
	}
	return counter&1 == 0
}

```