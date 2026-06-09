### 解题思路
* 本题可以用动态规划来解，但是并不是最简单的。因为所有的时长是正数，时间累积上肯定单调递增。
如果序列中的元素表示的是客户评价（有好评-正数，有差评-负数），此时优先使用动态规划
* 解题还是要用到动态规划的思想
massage(nums[0:i+2]) = max (massage(nums[0:i]) + nums[i] ,massage(nums[0:i+1]))

### 代码

```golang
func massage(nums []int) int {
	if len(nums) == 0 {
		return 0
	}

	maxFirst, maxSecond := 0, 0

	for _, num := range nums {
		if num+maxFirst > maxSecond {
			tmp := maxSecond
			maxSecond = num + maxFirst
			maxFirst = tmp
		} else {
			maxFirst = maxSecond
		}
		//fmt.Println(maxFirst, maxSecond)
	}
	if maxFirst > maxSecond {
		return maxFirst
	} else {
		return maxSecond
	}
}
```