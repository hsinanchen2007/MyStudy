### 解题思路
此处撰写解题思路
把0的位置存起来 对比diff的最大值
### 代码

```golang
func findMaxConsecutiveOnes(nums []int) int {
	if len(nums) == 0 {
		return 0
	}
	zeroLst := make([]int, 0)
	for i := 0; i < len(nums); i++ {
		if nums[i] == 0 {
			zeroLst = append(zeroLst, i)
		}
	}

	if len(zeroLst) < 2 {
		return len(nums)
	}
	max := zeroLst[1]
	for i := 1; i < len(zeroLst)-1; i++ {
		diff := zeroLst[i+1] - zeroLst[i-1] - 1
		if max < diff {
			max = diff
		}
	}

	if max < len(nums)-zeroLst[len(zeroLst)-2]-1 {
		max = len(nums) - zeroLst[len(zeroLst)-2] - 1
	}

	return max
}

```