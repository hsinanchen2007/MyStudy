关键在于关注红色和蓝色的位置即可，不需要关注白色的位置
```
func sortColors(nums []int)  {
	//红色的idx从0开始，蓝色的从len(nums) - 1开始
	//不用管当前数组中是具体是啥颜色
	redIdx, blueIdx := 0, len(nums) - 1
	for idx := 0; idx <= blueIdx; {
		if nums[idx] == 0 {
			//交换并增长红色的idx
			nums[redIdx], nums[idx] = nums[idx], nums[redIdx]
			redIdx++
			//红色的时候idx是要增长的
			idx++
		} else if nums[idx] == 2 {
			nums[idx], nums[blueIdx] = nums[blueIdx], nums[idx]
			blueIdx--
			//蓝色的时候不要增长idx，因为交换后可能idx对于的值可能是红色
			//这种情况就再循环一次让红色的case处理就行
		} else {
			idx++
		}
	}
}
```
