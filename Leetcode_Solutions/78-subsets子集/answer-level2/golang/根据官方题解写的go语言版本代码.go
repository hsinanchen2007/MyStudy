### 解题思路

思路见官方题解

### 递归

```golang
func subsets1(nums []int) [][]int {
	result := make([][]int, 0)
	result = append(result, make([]int, 0))
	for i := 0; i < len(nums); i ++ {
		end := len(result)
		curNum := nums[i]
		result = append(result, append(make([]int,0), curNum))
		for j := 1; j < end; j ++ {
			tmp := make([]int, len(result[j]))
			copy(tmp, result[j])
			cur := append(tmp, curNum)

			result = append(result, cur)
		}
	}
	return result
}
```

### 回溯

```golang
var total int

func backtrack(result *[][]int, cur *[]int, start int, nums []int) {
	if total == len(*cur) {
		tmp := make([]int, len(*cur))
		copy(tmp, *cur)
		*result = append(*result, tmp)
		return
	}

	for i := start; i < len(nums); i ++ {
		*cur = append(*cur, nums[i])
		backtrack(result, cur, i + 1, nums)
		*cur = (*cur)[:len(*cur) - 1]
	}
}

func subsets(nums []int) [][]int {
	result := make([][]int, 0)
	cur := make([]int, 0)
	for total = 0; total <= len(nums);total ++ {
		backtrack(&result, &cur, 0, nums)
	}
	return result
}
```

### 字典

```golang
func subsets3(nums []int) [][]int {
	result := make([][]int, 0)
	start := math.Pow(2, float64(len(nums)))
	end := math.Pow(2, float64(len(nums) + 1))
	for i := start; i < end; i ++ {
		binMask := strconv.FormatInt(int64(i), 2)
		curList := make([]int, 0)
		for i := 1; i < len(binMask); i ++ {
			if binMask[i] == '1' {
				curList = append(curList, nums[i-1])
			}
		}
		result = append(result, curList)
	}
	return result
}
```