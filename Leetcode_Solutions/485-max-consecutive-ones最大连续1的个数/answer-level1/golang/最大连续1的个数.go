### 解题思路
1. 定义c记录值为1的当前连续数量，另一个计数器maxC记录当前连续1数量的最大值
2. 遍历数组
	当遇到1时，c自增1
	当遇到0时，
		因为连续数量c需要重置为0。故而需要先与maxC比较，maxC记录两者较大值；尔后重置c为0
3. 最后返回c与maxC的较大值

### 代码

```golang
func findMaxConsecutiveOnes(nums []int) int {
    c, maxC, l := 0, 0, len(nums)
	for i := 0; i < l; i++ {
		if nums[i] == 1 {
			c++
		} else {
			if c > maxC {
				maxC = c
			}

			c = 0
		}
	}

	if c > maxC {
		return c
	} else {
		return maxC
	}
}
```