### 解题思路

(1)先将数组排序.
(2)在数组中查找第一个大于等于0的位置赋给index.
(3)若index值没变，说明整个数组都小于0或者整个数组都大于0，则返回后三个数的乘积即可.
(4)否则，index前面是负数，后面是正数，此时有两种情况：后三个最大的正数相乘或者两个最小的负数和最大的正数相乘.
(5)比较这两种情况，返回较大的那一种.

### 代码

```golang
func maximumProduct(nums []int) int {
	sort.Ints(nums)
	index := 0
	l := len(nums)
	for i := 0;i < l;i++ {
		if nums[i] >= 0 {
			index = i
			break
		}
	}
	if index == 0 {
		return nums[l - 1] * nums[l - 2] * nums[l - 3]
	}
	case1 := nums[l - 1] * nums[l - 2] * nums[l - 3]
	case2 := nums[0] * nums[1] * nums[l - 1]
	if case1 > case2 {
		return case1
	}
	return case2
}
```