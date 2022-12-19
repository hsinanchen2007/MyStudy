### 解题思路
瞎几把写就行


### 代码

```golang
func printNumbers(n int) []int {
	if n == 0 {
		return []int{}
	}
	sum := 1
	for n > 0 {
		sum = sum * 10
		n--
	}
	result := make([]int, 0,sum)
	for i := 1; i < sum; i++ {
		result = append(result, i)
	}
	return result

}
```