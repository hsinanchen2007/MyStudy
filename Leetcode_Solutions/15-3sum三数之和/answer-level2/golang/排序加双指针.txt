### 解题思路

因为要祛除重复，同时是求和运算，所以先排序可以让接下来的问题可以进行简化。遍历的时候，从第二个元素开始如果和前面一个元素相等，那么该元素跳过。内部通过减运算，当遍历到 i 时，问题就变成了从 i 之后的元素里找两个元素使其和为第 i 个元素的相反数，简化为两数之和问题。这部分可以通过双指针完成。

### 代码

```golang
func threeSum(nums []int) [][]int {
	var ans [][]int
	sort.Ints(nums)
	for i := 0; i < len(nums); i++ {
		if i > 0 && nums[i] == nums[i-1] {
			continue
		}
		if nums[i] > 0 {
			break
		}
		target := 0 - nums[i]
		left := i + 1
		right := len(nums) - 1
		for left < right {
			tmp := nums[left] + nums[right]
			if tmp == target {
				ans = append(ans, []int{nums[i], nums[left], nums[right]})
				for right-1 >= left && nums[right] == nums[right-1] {
					right--
				}
				for left+1 <= right && nums[left] == nums[left+1] {
					left++
				}
				left++
				right--
			} else {
				if tmp > target {
					right--
				} else {
					left++
				}
			}
		}
	}
	return ans
}
```