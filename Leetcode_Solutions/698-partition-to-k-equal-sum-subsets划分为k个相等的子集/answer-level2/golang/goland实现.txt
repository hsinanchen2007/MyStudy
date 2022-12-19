### 解题思路
同样是模拟K个子集，加了个特殊判断 if temp < target && temp + nums[0] > target {continue} 来减少对无效组合的计算

### 代码

```golang
var target int
func canPartitionKSubsets(nums []int, k int) bool {
	sort.Ints(nums)

	sum := 0
	for _,v := range nums{
		sum = sum + v
	}
	target = sum / k
    if k * target < sum || nums[len(nums) - 1] > target{
    	return false
	}

	l := len(nums)
	for nums[l - 1] == target {
		k --
		l --
	}

	return helper5(make([]int,k), nums, l)
}

func helper5(newGroups []int, nums []int, l int)bool{
	if l == 0 {
		return true
	}
    limitIndex := l - 1
	for i := 0; i < len(newGroups); i ++{
		temp := newGroups[i] + nums[limitIndex]
		if temp <= target{
			if temp < target && temp + nums[0] > target{
				continue
			}
			newGroups[i] = temp
			if helper5(newGroups, nums[:limitIndex], l - 1) {
				return true
			}
			newGroups[i] = temp - nums[limitIndex]
		}
	}
	return false
}
```