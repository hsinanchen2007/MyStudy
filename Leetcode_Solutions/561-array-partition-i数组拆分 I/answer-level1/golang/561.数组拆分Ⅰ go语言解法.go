### 解题思路

排序以后把下标为0，2，4，6...这些数相加求和就行了。

### 代码

```golang
func arrayPairSum(nums []int) int {
	sort.Ints(nums)
	res := 0
	for i,j := range nums {
		if i % 2 == 0 {
			res += j
		}
	}
	return res
}
```