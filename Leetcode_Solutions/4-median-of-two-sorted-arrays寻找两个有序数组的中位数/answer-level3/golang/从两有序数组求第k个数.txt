### 解题思路

时间复杂度O(n) ，空间复杂度O(1) 常量级别的

只需注意两个数组都是有序的，不需要排序，最多只需对其中一部分进行遍历就可以得到结果


### 代码

```golang

func median(nums []int) float64 {
	single := true

	if len(nums)%2 == 0 {
		single = false
	}
	mIndex := int(len(nums) / 2)

	if single {
		return float64(nums[mIndex])
	}

	return (float64(nums[mIndex-1]) + float64(nums[mIndex])) / 2
}

func median2(num1, num2 []int, single bool, mindex int) float64 {
	cusor := 0
	current := get(num1, 0)
	c1 := 1
	c2 := 0
	len1 := len(num1)
	len2 := len(num2)
	for i := 0; i < len1+len2; i++ {
		if cusor == mindex-1 {
			var next float64
			if c1 < len1 && c2 < len2 {
				if get(num1, c1) < get(num2, c2) {
					next = float64(get(num1, c1))
				} else {
					next = float64(get(num2, c2))
				}
			} else {
				if c1 < len1 {
					next = float64(get(num1, c1))
				} else {
					next = float64(get(num2, c2))
				}
			}

			if single {
				return next
			}

			return (current + next) / 2
		}

		if c1 < len1 && c2 < len2 {
			if get(num1, c1) < get(num2, c2) {
				current = get(num1, c1)
				c1++
			} else {
				current = get(num2, c2)
				c2++
			}
			cusor++
			continue
		}

		if c1 < len1 {
			current = get(num1, c1)
			c1++
			cusor++
			continue
		}

		if c2 < len2 {
			current = get(num2, c2)
			c2++
			cusor++
			continue
		}
	}
	return current
}

func get(nums []int, index int) float64 {
	if nums[0] <= nums[len(nums)-1] {
		return float64(nums[index])
	}
	return float64(nums[len(nums)-1-index])
}

func getTwo(num1, num2 []int, index int) float64 {
	if index+1 <= len(num1) {
		return get(num1, index)
	}
	return get(num2, index-len(num1))
}

func findMedianSortedArrays(nums1 []int, nums2 []int) float64 {
	len1 := len(nums1)
	len2 := len(nums2)

	if 0 == len1 || 0 == len2 {
		if 0 != len1 {
			return median(nums1)
		}
		if 0 != len2 {
			return median(nums2)
		}
	}

	single := true

	if (len1+len2)%2 == 0 {
		single = false
	}

	mIndex := int((len1 + len2) / 2)

	if get(nums1, len1-1) <= get(nums2, 0) {
		if single {
			return getTwo(nums1, nums2, mIndex)
		}
		return (getTwo(nums1, nums2, mIndex-1) + getTwo(nums1, nums2, mIndex)) / 2
	}

	if get(nums2, len2-1) <= get(nums1, 0) {
		if single {
			return getTwo(nums2, nums1, mIndex) 
		}
		return (getTwo(nums2, nums1, mIndex-1) + getTwo(nums2, nums1, mIndex)) / 2
	}

	if get(nums1, 0) < get(nums2, 0) {
		return median2(nums1, nums2, single, mIndex)
	}

	return median2(nums2, nums1, single, mIndex)
}

```