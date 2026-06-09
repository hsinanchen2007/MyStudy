### 解题思路
// 简单粗暴：将所有的数组按照 元素:频数（key:value）格式存储到map中
//           轮询map判断value是否有大于len(nums)/2数

### 代码

```golang
func majorityElement(nums []int) int {
	var frequency int
	var numMap = make(map[int]int, 0)

	if len(nums) == 0 {
		return 0
	}
	var frequencyNum = len(nums) / 2

	for i := 0; i < len(nums); i++ {
		if v, ok := numMap[nums[i]]; ok {
			v++
			numMap[nums[i]] = v
		} else {
			numMap[nums[i]] = 1
		}
	}

	for k, v := range numMap {
		if v > frequencyNum {
			frequency = k
		}
	}

	return frequency
}
```