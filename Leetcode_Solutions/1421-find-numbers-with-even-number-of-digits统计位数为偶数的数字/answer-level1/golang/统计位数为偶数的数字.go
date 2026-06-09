### 解题思路
由约束知，数组元素只能是2,4,6位数。

### 代码

```golang
func findNumbers(nums []int) int {
	n := 0
	for _, v := range nums {
		if (v / 10 != 0 && v / 100 == 0) || (v / 1000 != 0 && v / 10000 == 0) || (v / 100000 != 0 && v / 1000000 == 0) {
			n++
		}
	}
	return n
}
```