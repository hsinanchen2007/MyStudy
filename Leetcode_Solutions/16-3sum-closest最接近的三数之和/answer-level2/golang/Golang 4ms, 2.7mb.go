### 解题思路
此处撰写解题思路

### 代码

```golang
func threeSumClosest(nums []int, target int) int {
	sort.Ints(nums)
	similar := math.MaxInt64
	result := math.MaxInt64
	for i := 0; i < len(nums); i++ {
		start, end := i+1, len(nums)-1
		for start < end {
			tmp := nums[i] + nums[start] + nums[end]
			if target-tmp < 0 {
				if abs(target-tmp) <= similar {
					similar = abs(target - tmp)
					result = tmp
				}
				end -= 1
			} else if target-tmp > 0 {
				if abs(target-tmp) <= similar {
					similar = abs(target - tmp)
					result = tmp
				}
				start += 1
			} else {
				return tmp
			}
		}
	}
	return result
}

func abs(a int) int {
	if a < 0 {
		return -a
	}
	return a
}
```