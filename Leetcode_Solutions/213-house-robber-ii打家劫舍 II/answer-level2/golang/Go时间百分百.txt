这一题是打家劫舍经过简单变化而来的。说下思路，这题从最后结果来说，会出现如下情况：
第一间房子抢了，最后一间房子也抢了（不符合）
第一间房子没抢，最后一间房子被抢了（符合）
第一件房子抢了，最后一间房子没被抢（符合）
第一间房子没抢，最后一间房子也没抢（符合）
先判断最后一间房子抢没抢，即res[n]==res[n-1]，如果等于，那么最后一间房子没被抢，直接输出res[n]
如果不等于，代表最后一间被抢了，那么我们回头看看我们抢没抢第一间。如果也没抢第一间，那么没问题，直接输出res[n]，但如果第一间房子也被抢了，那么这个最大值就需要修改了，为max(rob[2....n],rob[1...n-1])。


```golang
func rob(nums []int) int {
    if len(nums) == 0 {
		return 0
	}
	if len(nums) == 1 {
		return nums[0]
	}
	if len(nums) == 2 {
		if nums[0] > nums[1] {
			return nums[0]
		} else {
			return nums[1]
		}
	}
	
	res := make([]int, len(nums))
	res[0] = nums[0]
	if nums[0] > nums[1] {
		res[1] = nums[0]
	} else {
		res[1] = nums[1]
	}

	arr := make([]int, len(nums))
	arr[1]=nums[1]
	
	i := 2
	for i < len(res) {
		if nums[i]+res[i-2] > res[i-1] {
			res[i] = nums[i] + res[i-2]
		} else {
			res[i] = res[i-1]
		}
		if nums[i]+arr[i-2] > arr[i-1] {
			arr[i] = nums[i] + arr[i-2]
		} else{
			arr[i] = arr[i-1]
		}
		i++
	}
	if res[i-1]==res[i-2] {//最末尾的房子没动
		return res[i-1]
	}else{
		if res[i-1]==arr[i-1]{//最开始的房子没动
			return res[i-1]
		}else {
			if res[i-2]>arr[i-1] {
				return res[i-2]
			}else {
				return arr[i-1]
			}
		}
	}
}
```