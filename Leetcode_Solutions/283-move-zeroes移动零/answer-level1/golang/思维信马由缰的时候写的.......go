```go
func moveZeroes(nums []int)  {
	var flag bool = false
	for i := 0; i < len(nums); i++ {
		// 看当前位置及以后是不是均为0 如果是 则说明排完了
		for k, v := range nums[i:] {
			if flag {
				return
			}

			if v == 0 {
				if k == len(nums[i:]) - 1 && !flag {
					flag = true
				}
				continue
			} else {
				break
			}
		}

		// 把0删除并在末尾补0 最后将指针向前移动一位 避免遍历时漏过0后面的那个元素
		if nums[i] == 0 {
			nums = append(nums[:i], nums[i + 1 :]...)
			nums = append(nums, 0)
			i -= 1
		}
	}
}
```
