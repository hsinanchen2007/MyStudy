### 解题思路
此处撰写解题思路
将取余2运算 换成 按位与1 运算 速度会加快很多 **beat 83.18%**
### 代码

```golang
func sortArrayByParityII(A []int) []int {
	newSlice := make([]int, len(A))
	oddIdx := 1
	evenIdx := 0
	for _, val := range A {
		if val & 1 != 0 {
			newSlice[oddIdx] = val
			oddIdx += 2
		} else {
			newSlice[evenIdx] = val
			evenIdx += 2
		}
	}
	return newSlice
}
```