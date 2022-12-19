执行用时: 8~12 ms  内存消耗: 5.6 MB

### 解题思路
转化为2个有序数组按整体 index 取值的问题。

代入 nums1 的索引值，如果小了就提升下界，大了就降低上界。

参考了 [@nojoker 的题解](https://leetcode-cn.com/problems/median-of-two-sorted-arrays/solution/jiang-qi-zhuan-wei-zhao-liang-ge-you-xu-shu-zu-de-/)

但我没看懂他公式的含义，自己重新又推了一遍。

### 代码

```golang
func getFromSortedArrays(nums1, nums2 []int, index int) int {
    if len(nums1) == 0 {
        return nums2[index]
    } else if len(nums2) == 0 {
        return nums1[index]
    }

    // i1, i2 为左右分割下标，左边的最大值小于等于右边的最小值
    // 基本条件:
    // i1 - 1 + i2 - 1 == index - 1 # 整体左边最后一个的下标为左边各自最后一个的下标之和
    // nums1[i1 - 1] <= nums2[i2]
    // nums2[i2 - 1] <= nums1[i1]
    // 0 <= i1 <= len(nums1)
    // 0 <= i2 <= len(nums2)
    // 推导:
    // i2 = index - i1 + 1
    // 0 <= index - i1 + 1 <= len(nums2)
    // -index - 1 <= -i1 <= len(nums2) - index - 1
    // -len(nums2) + index + 1 <= i1 <= index + 1
    lower, upper := 0, len(nums1)
    if v := -len(nums2) + index + 1; v > lower{
        lower = v
    }
    if v := index + 1 ; v < upper {
        upper = v
    }
    var i1, i2 int
    for {
        i1 = (lower + upper) >> 1
        i2 = index - i1 + 1
        if i2 - 1 >= 0 && i1 < len(nums1) && !(nums2[i2 - 1] <= nums1[i1]) {
            lower = i1 + 1
        } else if i1 -1 >= 0 && i2 < len(nums2) && !(nums1[i1 - 1] <= nums2[i2]) {
            upper = i1 - 1
        } else {
            break
        }
    }
    if i1 == 0 {
        return nums2[i2 -1]
    }
    if i2 == 0 {
        return nums1[i1 -1]
    }
    v1, v2 := nums1[i1 -1], nums2[i2-1]
    if v1 > v2 {
        return v1
    }
    return v2
}

func findMedianSortedArrays(nums1 []int, nums2 []int) float64 {
    totalLength := len(nums1) + len(nums2) 
    leftIndex := (totalLength - 1) / 2
    rightIndex := totalLength / 2 
    if leftIndex != rightIndex {
        left := getFromSortedArrays(nums1, nums2, leftIndex)
        right:= getFromSortedArrays(nums1, nums2, rightIndex)
        return float64(left + right) / 2
    }
    return float64(getFromSortedArrays(nums1, nums2, leftIndex))
}
```