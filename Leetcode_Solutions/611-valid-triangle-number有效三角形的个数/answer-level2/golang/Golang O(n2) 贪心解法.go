### 解题思路

先用标准库的`sort`将数组`[]int`排序。
根据三角形边长定理：a + b > c。

例如 `[1,2,3,4,5]`, 循环`c`从右边最大值开始，`b`初始化为比`c`小一位， `a`从0开始，如果`a+b>c`，那么a到b之间的个数都可以组成三角形。

### 代码

```golang
import (
	"sort"
)

func triangleNumber(nums []int) int {
	// check if there is more than 3 nums
	if len(nums) < 3 {
		return 0
	}

	// first sort the nums.
	sort.Ints(nums)

	// the answer.
	ans := 0
	// the length of nums.
	n := len(nums)
	// start to loop backwards.
	for c := n-1; c > 1; c-- {
		b := c - 1
		a := 0 
		for a < b {
			if nums[a] + nums[b] > nums[c] {
				ans += b - a
				b--
			} else {
				a++
			}
		}
	}
	return ans


}

```