思路：双指针，滑动窗口
```
func minSubArrayLen(s int, nums []int) int {
	numLen := len(nums)
	// +1是为了帮助判断整个数组的所有元素加和也达不到s的情况出现
	minLen := numLen + 1
	// 记录窗口内连续和的变量
	var tmpSum int
	// 快指针
	var j int
	for i := 0; i < numLen; i, j = i+1, j+1 {
		for j < numLen {
			// 窗口右扩
			tmpSum += nums[j]
			if tmpSum >= s {
				curLen := j - i + 1
				if curLen < minLen {
					minLen = curLen
				}

				break
			}
			j++
		}

		for {
			// 窗口左缩
			tmpSum -= nums[i]
			// 对窗口缩小一位后总和仍大于s的追加检查
			// e.g:
			// .... 1,1,100,....        s=50
			// 第一次进入窗口是 1,1,100
			// 窗口左移：... 1,100,... 和仍大于s
			if tmpSum >= s {
				i++
			} else {
				break
			}
		}
		curLen := j - i + 1
		if curLen < minLen {
			minLen = curLen
		}
	}

	if minLen == numLen+1 {
		// 表明在遍历了整个数组之后，也没有达到条件：tmpSum >= s，即数组里所有元素加起来也没有到达s
		minLen = 0
	}
	return minLen
}
```

![image.png](https://pic.leetcode-cn.com/ec813bccf16a2d4458522baabc5ca155462e5e878789bff6e10c506c3a704532-image.png)
