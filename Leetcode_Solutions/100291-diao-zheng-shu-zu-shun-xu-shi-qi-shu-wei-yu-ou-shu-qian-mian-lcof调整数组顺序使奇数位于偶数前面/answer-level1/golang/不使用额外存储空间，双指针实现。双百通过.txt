不实用额外存储空间，头指针 如果为偶数 尾指针为奇数则交换
否则，判断头指针如果是奇数头指针前进一步，
如果尾指针如果是偶数则尾指针向后一步

```

func exchange(nums []int) []int {
	for i, j := 0, len(nums)-1; i < j; {
		if nums[i]%2 == 0 && nums[j]%2 != 0 {
			nums[i], nums[j] = nums[j], nums[i]
			i++
			j--
		} else {
			if nums[i]%2 != 0 {
				i++
			}
			if nums[j]%2 == 0 {
				j--
			}
		}
	}
	return nums
}

```
