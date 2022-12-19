### 解题思路
使用双指针

### 代码

```golang
func threeSumClosest(nums []int, target int) int {
	var result int
	sortInt := sort.IntSlice(nums)
	sortInt.Sort()
	length := len(nums)
	// 最小值大于等于target
	if nums[0] + nums[1] + nums[2] >= target {
		return nums[0] + nums[1] + nums[2]
	}
	// 最大值小于等于target
	if nums[length - 3] + nums[ length - 2] + nums[length -1] <= target {
		return nums[length - 3] + nums[length -2] + nums[length -1]
	}

	// k是开始位置
	// i是中间位置
	// j是结束位置
	minOffset := -1
	compareMinOffset := func(k, i, j int) int {
		from := nums[k] + nums[i] + nums[j]

		offset := from - target
		if offset < 0 {
			offset = 0 - offset
		}
		if  minOffset == -1 || offset < minOffset  {
			minOffset = offset
			result = from
		}

		if from < target {
			return -1
		}
		if from > target {
			return 1
		}
		return 0
	}
	for k := 0; k < length - 2; k++ {
		i := k + 1
		j := length - 1
		for i < j {
			c := compareMinOffset(k,i,j)
			if c == 0 { // 和目标值相等，最短距离直接return
				return result
			}else if c == - 1 { // 三数和小于目标值 移动i
				i++
			}else if c == 1 { // 三叔和大于目标值 移动j
				j--
			}
		}
	}
	return result
}
```

### 执行结果
![image.png](https://pic.leetcode-cn.com/57ba6bb926bf1513cd3f50b61a7477287b32a219ea6fa47eb94d96acd4cc97e2-image.png)
