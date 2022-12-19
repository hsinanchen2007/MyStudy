### 解题思路
1、先按照从大到小排序
2、依次计算数列总的差值总额,例如：[8,5,4,0,0,0]，那么差值总额应该是2，如果数列种0的个数超过差值总额，那么就可以补齐
3、有一个小坑，正常情况下，0不应该超过2个的（一副扑克大小王也就2个）

### 代码

```golang
func isStraight(nums []int) bool {
    sort.Slice(nums, func(i int, j int) bool {  
		return nums[i] > nums[j]
	})

	zeroTimes, diffSum := 0, 0

	for i := 0; i < len(nums)-1; i++ {

		if nums[i] == 0 || nums[i+1] == 0 {
			break
		}

		diff := nums[i] - nums[i+1] - 1

		if diff == 0 {
			continue
		}

        if diff == -1 {
            return false
        }


		diffSum = diffSum + diff
	}

	for i, _ := range nums {
		if nums[i] == 0 {
			zeroTimes++
		}
	}

	if zeroTimes >= diffSum {
		return true
	}

	return false
}
```