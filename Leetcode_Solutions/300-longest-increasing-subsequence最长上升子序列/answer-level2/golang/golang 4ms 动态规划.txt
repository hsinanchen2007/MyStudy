核心思想： 维护一个最小有序数组。
- nums = [10 9 2 5 3 4 101 18], tail = []
- i = 0，tail = [10] ，size = 1
- i = 1，tail = [9]，size = 1，因为9比10小，且没有比9更小的数，所以直接把10替换为9
- i = 2，tail = [2]，size = 1，同上
- i = 3，tail = [2, 5]， size = 2， tail的最后一个数字小于5，所以可以直接把5放到后面
- i = 4，tail = [2, 3]， size = 2， 2 < 3 < 5，所以3相对于5是更优解
- i = 5，tail = [2,3,4]，size = 3，4 > 3,直接append
- i = 6，tail = [2,3,4,101]， size = 4， 101 > 4,直接append
- i = 7， tail = [2,3,4,18],  size = 4，4 < 18 < 101。 所以结果为 4
- 优化： 使用二分法找到 当前数需要插入到tail中的位置
```
func lengthOfLIS(nums []int) int {
	size := 0
	tail := make([]int, len(nums))
	for i := 0; i < len(nums); i++ {
		if size == 0 || tail[size-1] < nums[i] {
			tail[size] = nums[i]
			size++
		} else {
			x, y := 0, size-1
			for x < y {
				mid := (x + y) / 2
				if tail[mid] < nums[i] {
					x = mid + 1
				} else {
					y = mid
				}
			}
			tail[x] = nums[i]
		}
	}
	return size

}
```