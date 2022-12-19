```
// 分n + m 为偶数和奇数两种情况进行考虑
// 对nums1进行遍历，j = k - i 保证了len(nums1[:i] + nums2[:j]) = len(nums1[i:] + nums2[j:])
// 此时，只要找到max(nums1[:i] + nums2[:j]) <= min(nums1[i:] + nums2[j:])的情况即为中位数
// 保证m < n
func findMedianSortedArrays(nums1 []int, nums2 []int) float64 {
    
    if len(nums1) > len(nums2) {
        return findMedianSortedArrays(nums2, nums1)
    }
    var m, n = len(nums1), len(nums2)
    if m == 0 {
        return mid(nums2)
    }
    
     var res float64 = 0
    
    // m + n为偶数
    if (m+n)%2 == 0 {
         k := (m+n)/2  // i + j = k
        // i <= m假定nums1[i]属于right
        for i := 0; i <= m; i++ {
            j := k - i
            left := max(i, j, nums1, nums2)
            right := min(i, j, nums1, nums2)
            if left <= right  {
                res = float64(left + right)/2
                break
            }
        }
    } else {
         k := (m+n+1)/2  // j = k - i
        for i := 0; i <= m; i++ {
            j := k - i
            left := max(i, j, nums1, nums2)
            right := min(i, j, nums1, nums2)
            
            if left <= right  {
                res = float64(left)
                break
            }
        }     
    }
   
    return res
}

// left:考虑边界条件
func max(i, j int, nums1, nums2 []int) int {

	if i == 0 {
		return nums2[j-1]
	}
	if j == 0 {
		return nums1[i-1]
	}

	if nums1[i-1] > nums2[j-1] {
		return nums1[i-1]
	} else {
		return nums2[j-1]
	}
}

// right：考虑边界条件
func min(i, j int, nums1, nums2 []int) int {
	if i == len(nums1) {
		return nums2[j]
	}
	if j == len(nums2) {
		return nums1[i]
	}
	if nums1[i] < nums2[j] {
		return nums1[i]
	} else {
		return nums2[j]
	}
}

// 单独一个数组计算出中位数
func mid(nums []int) float64 {
    l := len(nums)
    if l == 0 {return 0}
    if l == 1 {
        return float64(nums[0])
    }
    
    tmp := l/2
    if l % 2 == 1 {
        return float64(nums[tmp])
    } else {
        return float64(nums[tmp]+nums[tmp-1])/2
    }    
}



```