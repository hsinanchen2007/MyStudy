### 解题思路

这个题最后还需要判断一下，`nums[l] == l`，如果满足的话，即整个数组有序，返回`l+1`即可。

### 代码

```golang
func missingNumber(nums []int) int {
    if nums == nil || len(nums) == 0 {
        return 0
    }

	l, r := 0, len(nums) - 1
	for l < r {
		mid := l + (r-l)>>1
		if mid < nums[mid] {
			r = mid
		} else {
			l = mid + 1
		}
	}
    if nums[l] == l {
        return l+1
    }
    return l
}

```