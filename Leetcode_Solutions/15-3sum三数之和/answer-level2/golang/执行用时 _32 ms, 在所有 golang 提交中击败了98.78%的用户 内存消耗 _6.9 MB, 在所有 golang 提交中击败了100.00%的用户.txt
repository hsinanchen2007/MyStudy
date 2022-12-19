### 解题思路
golang解答
执行用时 :32 ms, 在所有 golang 提交中击败了98.78%的用户
内存消耗 :6.9 MB, 在所有 golang 提交中击败了100.00%的用户

### 代码
```golang
import "sort"

func threeSum(nums []int) [][]int {
	res := [][]int{}
	if len(nums) < 3 {return res}
	sort.Ints(nums)
	length := len(nums)

	if nums[0] <= 0 && nums[length - 1] >= 0 {
		for i:=0;i<length-2;i++{
			if nums[i] > 0 {break}
            // 避免添加重复的结果
			// i>0 是为了防止nums[i-1]溢出
			if i > 0 && nums[i] == nums[i-1] {
				continue
			}
			first := i+1
			last := length - 1
			for first<last {
				if nums[i] * nums[last] > 0 {break}
				result := nums[i] + nums[first] + nums[last]
				switch {
				case result < 0:
					// 较小的 first 需要变大
					first++
				case result > 0:
					// 较大的 last 需要变小
					last--
				default:
					res = append(res, []int{nums[i], nums[first], nums[last]})
					// 为避免重复添加，first 和 last 都需要移动到不同的元素上。
					first, last = next(nums, first, last)
				}
			}
		}
		return res
	}
	return res
}

func next(nums []int, l, r int) (int, int) {
	for l < r {
		switch {
		case nums[l] == nums[l+1]:
			l++
		case nums[r] == nums[r-1]:
			r--
		default:
			l++
			r--
			return l, r
		}
	}

	return l, r
}
```