**结果：**
![1.png](https://pic.leetcode-cn.com/8ad231ed5407b9720278955bbfbe36274cc61a1bb8aeb867d27fb4e341e00e0e-1.png)

**思路：**
1. 数组长度过小(len<=2)时直接判断
2. 如果firstValue < lastValue，说明数组没有经过旋转，直接返回firstValue
3. 只要经过旋转就可以通过二分法找到：left<=middle时，取右侧继续二分；left>middle时，取左侧继续二分，直到left与middle下标重合就结束

**代码：**
```
func findMin(nums []int) int {
	lens := len(nums)
	left := 0
	right := lens - 1
	mid := right / 2

	if left == mid {
		if nums[left] < nums[right] {
			return nums[left]
		}
		return nums[right]
	}
	if nums[left] < nums[right] {
		return nums[left]
	}

	for {
		if nums[left] <= nums[mid] {
			left = mid
			mid = (left + right) / 2
		} else if nums[left] > nums[mid] {
			right = mid
			mid = (left + right) / 2
		}

		if mid == left {
			return nums[mid+1]
		}
	}
}

```