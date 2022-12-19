看到这个题的第一反应，把三数之和拿过来套一套。结果就。。。
![image.png](https://pic.leetcode-cn.com/f3b259b69bc1d207394a3bec9605095ca363e0dc8ae5583b17af6c7dc1fb793e-image.png)
所以标题的说的最快是指写代码时间最快。
虽然写的快，但是执行的慢啊，哈哈，打扰了各位  ^-^
```
func fourSum(nums []int, target int) [][]int {
	res := [][]int{}
	sort.Ints(nums)
	for i := 0; i < len(nums)-3; i++ {
		if i > 0 && nums[i] == nums[i-1] {
			continue
		}
		tmp := threeSum(nums[i+1:], target-nums[i])
		if tmp != nil {
			for _, t := range tmp {
				t = append(t, nums[i])
				res = append(res, t)
			}
		}
	}
	return res
}

func threeSum(nums []int, target int) [][]int {
	res := [][]int{}
	sort.Ints(nums)
	for i := 0; i < len(nums)-2; i++ {
		if i-1 >= 0 && nums[i] == nums[i-1] {
			continue
		}
		tmp := twoSum(nums[i+1:], target-nums[i])
		if tmp != nil {
			for _, t := range tmp {
				t = append(t, nums[i])
				res = append(res, t)
			}
		}
	}
	return res
}

func twoSum(nums []int, target int) [][]int {
	has := make(map[int]bool)
	drop := make(map[int]bool)
	res := [][]int{}
	for i := 0; i < len(nums); i++ {
		if has[target-nums[i]] {
			if drop[target-nums[i]] == false {
				res = append(res, []int{target - nums[i], nums[i]})
				drop[target-nums[i]] = true
			}
		} else {
			has[nums[i]] = true
		}
	}
	return res
}
```
