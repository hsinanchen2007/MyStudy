思路：动态规划，要求最长上升子序列，首先每一个位置的最长子序列可以根据前面每一个比他小的元素的最长子序列+1得到。特例0，1，2可以直接得出结果。
每一个位置的默认上升序列是1，就是他本身，然后遍历他前面的比他小的元素，看那些元素的对应的最长子序列是多少，因为要取最大值，所以第一次给r[i]赋值后，后面每一次都要跟r[i]做比较得出r[i]的最大值。最终遍历r,得出所有位置最长子序列中最长的一个
```
func lengthOfLIS(nums []int) int {
    if len(nums) == 0 {
		return 0
	}else if len(nums) == 1 {
		return 1
	}else if len(nums) == 2 {
		if nums[1] > nums[0] {
			return 2
		}else {
			return 1
		}
	}

	r := make([]int, len(nums))
	for i := 0; i<len(r);i++  {
		r[i] = 1;
	}
	for i := 1; i<len(nums);i++  {
		for j:=0;j<i;j++  {
			if nums[i] > nums[j] {
				s := r[j] + 1
				if r[i] > s {
					s = r[i]
				}
				r[i] = s
			}
		}
	}
	max := 0
	for _,v := range r{
		if v > max {
			max = v
		}
	}
	return max
}
```
