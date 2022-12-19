### 解题思路
1. 设置两个指针 i，j 分别指向数组的开头和结尾
2. 如果 i 处的元素为奇数，i 后移一位
3. 如果 j 处的元素为偶数，j 前移一位
4. 否则交换 i，j 处的元素

时间复杂度O(n)，遍历数组  
空间复杂度 O(1)，因为只创建了两个指针  
### 代码

```golang
func exchange(nums []int) []int {
	i, j := 0, len(nums)-1
	for i < j {
		if nums[i]%2 == 1 {
			i++
		} else if nums[j]%2 == 0 {
			j--
		} else {
			nums[i], nums[j] = nums[j], nums[i]
			i++
			j--
		}
	}
	return nums

}
```