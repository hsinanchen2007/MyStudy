第一种：暴力法
这种方法的时间和空间效率都很差，特别是中间空洞过多时，空间占用更多，例如：[-1, 1000000000]，这里要是申请空间的话，要申请1000000000/8 + 1个字节
```
func firstMissingPositive(nums []int) int {
	maxNum := 0
	for _, num := range nums {
		if num <= 0 {
			continue
		}
		if num > maxNum {
			maxNum = num
		}
	}

	idxInfo := make([]uint8, maxNum + 1)
	for _, num := range nums {
		if num <= 0 {
			continue
		}
		idxInfo[num / 8] |= 1 << uint(num % 8)
	}

	for i := 1; i < maxNum; i++ {
		if idxInfo[i / 8] & (1 << uint(i % 8)) == 0 {
			return i
		}
	}

```

方法二：map，用这种方式，可以解决上面空洞过多导致的空间过大的问题，并且查找也更快，但还是比较慢
```
func firstMissingPositive(nums []int) int {
	maxNum := 0
	idxMap := make(map[int]struct{})
	for _, num := range nums {
		idxMap[nums] = struct{}{}
	}

	for i := 1; i < maxNum; i++ {
		if _, exist := idxMap[i]; exist == false {
			return i
		}
	}

	return maxNum + 1
}
```


方法三：桶排序，我看前面称这个思路是抽屉原理，觉得应该叫桶排序法更合适


```golang
func firstMissingPositive(nums []int) int {
	for i := 0; i < len(nums); i++ {
		for nums[i] != i + 1 {
			idx := nums[i] - 1 // 这个数应该在哪个位置
			if idx < 0 || idx >= len(nums) || nums[i] == nums[idx] {
				break
			}
			nums[i], nums[idx] = nums[idx], nums[i]
		}
	}

	for i := 0; i < len(nums); i++ {
		if nums[i] != i + 1 { // 这个位置应该放i+1
			return i + 1 // 缺少i+1
		}
	}

	return len(nums) + 1
}
```