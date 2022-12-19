### 解题思路

先求0-n序列的和，再减去所给序列的和，即为缺失的数

### 代码

```golang
func missingNumber(nums []int) int {
	n := len(nums)
	sum1 := (n * n + n) / 2
	sum2 := 0
	for _,i := range nums {
		sum2 += i
	}
	return sum1 - sum2
}
```