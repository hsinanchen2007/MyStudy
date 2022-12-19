

```golang
func reversePairs(nums []int) int {
    if nums == nil || len(nums) < 2 {
		return 0
	}
	return process(nums, 0, len(nums)-1)
}

func process(nums []int, left, right int)int {
	if left == right {
		return 0
	}
	mid := left + (right-left)/2
	return process(nums, left, mid)+process(nums, mid+1, right)+merge(nums, left, mid, right)
}

func merge(nums []int, left, mid, right int) int{
	help := []int{}
	p1, p2 := left, mid+1
	res := 0
	for p1 <= mid && p2 <= right {
		if nums[p1] <= nums[p2] {
			help = append(help, nums[p1])
			p1++
		} else {
            res +=mid-p1+1
			help = append(help, nums[p2])
			p2++
		}
	}
	for p1 <= mid {
		help = append(help, nums[p1])
		p1++
	}
	for p2 <= right {
		help = append(help, nums[p2])
		p2++
	}
	for i := 0; i < len(help); i++ {
		nums[left+i] = help[i]
	}
	return res
}

```