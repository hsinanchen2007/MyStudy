### 解题思路
利用hash表 ，hash存取 o(1),按照nums遍历，当 hash表中不存在当前值减一的时候，设置start，当不存在当前值+1的时候结束运算，每次计算最大值

### 代码

```golang
func longestConsecutive(nums []int) int {
	if len(nums) <= 1 {
		return len(nums)
	}
	m := make(map[int]bool)
	for i := 0; i < len(nums); i++ {
		m[nums[i]] = true
	}
	start := nums[0]
	end := nums[0]
	res := 0
	for i := 0; i < len(nums); i++ {
		if _, ok := m[nums[i]-1]; !ok {
			start = nums[i]
			end = start
			for {
				if _, ok := m[end+1]; !ok {
					break
				}
				end = end + 1
			}
			res = maxINT(res, end-start+1)
		}

	}
	return res
}
func maxINT(a, b int) int {
	if a > b {
		return a
	}
	return b
}

```