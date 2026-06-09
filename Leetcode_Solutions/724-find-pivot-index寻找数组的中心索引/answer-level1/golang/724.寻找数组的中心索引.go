### 解题思路

数组元素总和为sum，当前索引左边所有元素的和为cur_sum，当cur_sum满足cur_sum == sum - 当前元素值 - cur_sum 时，当前索引即为中心索引。

### 代码

```golang
func pivotIndex(nums []int) int {
	sum := 0
	cur_sum := 0
	for _,i := range nums {
		sum += i
	}
	for k,v := range nums {
		if cur_sum == sum - v - cur_sum {
			return k
		}
		cur_sum += v
	}
	return -1
}
```