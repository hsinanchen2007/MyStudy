```
func max(a int, b int) int {
	if a > b {
		return a
	} else {
		return b
	}
}

func helper(i int, nums []int, tag bool, dpy []int, dpn []int) int {
	if i >= len(nums) {
		return 0
	}

	if tag {
		//缓存，去除重复计算
		if dpy[i] != -1 {
			return dpy[i]
		}
		dpy[i] = helper(i+1, nums, false, dpy, dpn) + nums[i]
		return dpy[i]
	} else {
		//缓存，去除重复计算
		if dpn[i] != -1 {
			return dpn[i]
		}
		dpn[i] = max(helper(i+1, nums, false, dpy, dpn), helper(i+1, nums, true, dpy, dpn))
		return dpn[i]
	}
}

func massage(nums []int) int {
	if len(nums) == 0 {
		return 0
	}
	var dpy []int = make([]int, len(nums))
	var dpn []int = make([]int, len(nums))
	for i := 0; i < len(nums); i++ {
		dpy[i] = -1
		dpn[i] = -1
	}
	helper(0, nums, true, dpy, dpn)
	helper(0, nums, false, dpy, dpn)
	var tmp = max(dpy[0], dpn[0])

	return tmp
}
```
动态规划
采用dpy记录当前节点预约最优解时的缓存
采用dpn记录当前节点不预约最优解时的缓存