### 解题思路
从右往左找到降序的元素a，然后再升序过程中找到第一个比该元素大的元素b，重点，交换 ab,将最后的升序重排为降序

### 代码

```golang

func nextPermutation(nums []int) {
	if len(nums) <= 1 {
		return
	}
	var has bool
	var tep, index int
	for i := len(nums) - 1; i >= 1; i-- {
		if nums[i] > nums[i-1] {
			tep = nums[i-1]
			index = i - 1
			has = true
			break
		}

	}

	for i := len(nums) - 1; i >= index+1; i-- {
		if nums[i] > tep {
			nums[i], nums[index] = nums[index], nums[i]
			break
		}
	}
	if has {
		for i := index + 1; i <= (len(nums)-1+index+1)/2; i++ {
			nums[i], nums[len(nums)-i+index] = nums[len(nums)-i+index], nums[i]
		}
	} else {
		sort.Ints(nums)
	}
}

```