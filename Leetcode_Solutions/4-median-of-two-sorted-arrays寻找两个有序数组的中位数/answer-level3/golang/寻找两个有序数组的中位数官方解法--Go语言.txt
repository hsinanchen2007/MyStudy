```
func findMedianSortedArrays(nums1 []int, nums2 []int) float64 {
    m := len(nums1)
    n := len(nums2)
    // 比较两个数列的长度，保证i所在的数列最大
    if m > n {
        nums1, nums2 = nums2, nums1
        m, n = n, m
    }
    
    
    iMin := 0
    iMax := m
    halfLen := (m+n+1)/2
    // 在iMin和iMax之间搜索，找到匹配的i
    for{
        if iMin > iMax {
            break
        }
        i := (iMin + iMax) / 2
        j := halfLen - i
        if i < iMax && nums1[i] < nums2[j-1] {
            iMin = i + 1
        } else if i > iMin && nums1[i-1] > nums2[j] {
            iMax = i - 1
        } else {
            maxLeft := 0
            if i == 0 {
                maxLeft = nums2[j-1]
            } else if j == 0 {
                maxLeft = nums1[i-1]
            } else if nums1[i-1] >= nums2[j-1]{
                maxLeft = nums1[i-1]
            } else {
                maxLeft = nums2[j-1]
            }
            if (m+n)%2==1 {
                return float64(maxLeft)
            }
            
            minRight := 0
            if i == m {
                minRight = nums2[j]
            }else if j == n {
                minRight = nums1[i]
            }else if nums1[i] <= nums2[j] {
                minRight = nums1[i]
            } else {
                minRight = nums2[j]
            }
            
            return float64(maxLeft + minRight) / 2.0
        }
    }
    return 0.0
}
```
