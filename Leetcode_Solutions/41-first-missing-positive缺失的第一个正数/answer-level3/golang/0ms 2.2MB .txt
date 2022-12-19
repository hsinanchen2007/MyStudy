### 解题思路
此处撰写解题思路

- 数组长度为1单独考虑
- 如果数组中的数值都大于 nums的长度sLen ，那么结果肯定是 1。也就是数值都大于2，结果肯定为1.
- 如果数组中的数值都小于等于 0 ，那么结果肯定是 1
- 如果有一部分数在(0,sLen),一部分在别的范围，也就是说在[1,sLen]的数的个数小于sLen，无法填满长度为sLen的桶，必然有空隙，这个空隙就是


### 代码

```golang
func firstMissingPositive(nums []int) int {

	sLen := len(nums)
	if sLen == 0 {
		return 1
	}

	if sLen == 1 {
		if nums[0] == 1 {
			return 2
		}
		return 1
	}

	i := 0
	for i < sLen {

		for nums[i] >= 1 && nums[i] <= sLen && nums[i]-1 > i {
			tmpID := nums[i] - 1

			//如果给要交换的地方的数值一样，就跳出来，不然这里就会一直死循环了
			if nums[i] == nums[tmpID] {
				break
			}
			nums[i], nums[tmpID] = nums[tmpID], nums[i] //这里交换几次，整个程序 剩余可交换次数就少几次 ；所以整体还是O(n)
			// i++
			// fmt.Println(nums)
		}

		if nums[i] < 1 || nums[i] > sLen {
			i++
			continue
		}

		nums[nums[i]-1] = nums[i]
		i++

	}

	// fmt.Println(nums)

	for i := range nums {
		if i != nums[i]-1 {
			return i + 1
		}
	}

	return nums[sLen-1] + 1
}
```