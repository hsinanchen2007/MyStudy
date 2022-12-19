### 解题思路
1. 动态规划
2. 仿照No55题，从0开始迭代，设定当前index之后能达到的位置之间各index的最短跳跃次数，如果有更小的跳跃次数则覆盖。

### 代码

```golang

func jump(nums []int) int {
	k := 0
	buf := make([]int, len(nums))
	for i := 0; i < len(nums); i++ {
		if nums[i]+i > k {
			k = nums[i] + i
			for j := i + 1; j <= k && j < len(nums); j++ {
				if buf[j] == 0 {
					buf[j] = buf[i] + 1
				} else if buf[j] > buf[i]+1 {
					buf[j] = buf[i] + 1
				}
			}
		}
	}
	return buf[len(buf)-1]
}
```