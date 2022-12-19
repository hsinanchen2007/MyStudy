### 解题思路
二分法努力找到边界点，使得两个数组的左边加起来和右边加起来个数相同

### 代码

```golang
func findMedianSortedArrays(nums1 []int, nums2 []int) float64 {
    // 找到一个值让左右两边的数相等
    l1 := len(nums1)
    l2 := len(nums2)

    // 前提是第一个数组短
    if l1 > l2 {
        return findMedianSortedArrays(nums2, nums1)
    }

    // 总长
    k := (l1 + l2 + 1) / 2
    // 对短的数组用二分法
    left := 0
    right := l1

    var m1, m2 int
    for left < right {
        m1 = left +(right - left) / 2
        m2 = k - m1

        if nums1[m1] < nums2[m2-1] {
            left = m1 + 1
        } else {
            right = m1
        }
    }
    m1 = left
    m2 = k - m1 

    a := math.MinInt32
    if m1 > 0 {
        a = nums1[m1 - 1]
    }
    b := math.MinInt32
    if m2 > 0 {
        b = nums2[m2 - 1]
    } 
    c1 := max(a, b) 
    // 奇数个取中间的
    if (l1 + l2) % 2 == 1 {
        return float64(c1)
    }
    
    a = math.MaxInt32
    if m1 < l1 {
        a = nums1[m1]
    }
    b = math.MaxInt32
    if m2 >= 0 && m2 < l2 {
        b = nums2[m2]
    }
    c2 := min(a, b)
    return float64(float64(c1 + c2) / 2.0)
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}

func min(a, b int) int {
    if a < b {
        return a
    }
    return b
}
```