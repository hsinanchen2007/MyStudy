### 解题思路
题不难就是要想好思路，重新设计了好几次，才写出来

### 代码

```golang
func plusOne(digits []int) []int {
	for i:=len(digits)-1; i>=0; i-- {
		if digits[i] != 9 {
			digits[i]++
			return digits
		} else {
			digits[i] = 0
		}
	}
	return append([]int{1}, digits...)
}
```