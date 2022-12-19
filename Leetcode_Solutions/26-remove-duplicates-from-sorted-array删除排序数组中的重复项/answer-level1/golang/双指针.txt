### 解题思路
第一个指针 i 代表结果数组的下标，第二个指针 j 代表下一个比 i 所在元素大的第一个元素下标。
交换 i 和 j，更新 j，直到 j 到达原数组末尾。返回 i+1.

需要注意的一下边界控制。

### 代码

```golang
func removeDuplicates(nums []int) int {
    i, j := 0, 1
	for j < len(nums) {
		// j 找到第一个比 i 大的数字
		for nums[j] <= nums[i] {
			j++
			if j >= len(nums) {
				return i + 1
			}
		}
		// 交换数字
		i++
		nums[i], nums[j] = nums[j], nums[i]
		j++
	}
	return i + 1
}
```