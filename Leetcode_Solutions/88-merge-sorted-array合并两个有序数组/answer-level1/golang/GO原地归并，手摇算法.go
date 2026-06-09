### 解题思路

使用手摇算法进行原地归并，时间复杂度O(N),空间复杂度O(1)

### 代码

```golang
func merge(nums1 []int, m int, nums2 []int, n int) {
	nums1 = append(nums1[:m], nums2[:n]...)
	if n == 0 || m == 0 {
		return
	}
	var i, l, r = 0, m, m
	for i < l && r < m+n {
		for i < m && nums1[i] <= nums1[r] {
			i++
		}
		for r < m+n && nums1[i] >= nums1[r] {
			r++
		}
		convert(nums1, i, l, r-1)
		i += r - l + 1
		l = r
	}
}

/*
手摇算法，内存翻转算法，原地归并
nums[l....mid....r] -> nums[r.....mid....l]
*/
func convert(nums []int, l, mid, r int) {
	reverse(nums, l, mid-1)
	reverse(nums, mid, r)
	reverse(nums, l, r)
}

func reverse(nums []int, l, r int) {
	for l < r {
		nums[l], nums[r] = nums[r], nums[l]
		l++
		r--
	}
}

```