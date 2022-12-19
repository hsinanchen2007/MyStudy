### 解题思路
这里用到的是归并排序中的有序合并思想，将两个有序数组进行合并，合并完成之后求他们中位索引，如果中位有两个索引，就求两个索引所在值的平均数

### 代码

```golang
func findMedianSortedArrays(nums1 []int, nums2 []int) float64 {
    nums1Len, nums2Len := len(nums1), len(nums2)
    numsLen := nums1Len+nums2Len
    nums1Index, nums2Index := 0, 0
    nums := make([]int, 0, numsLen)
    if nums1Len != 0 && nums2Len != 0 {
            for nums1Index < nums1Len && nums2Index < nums2Len {
                if nums1[nums1Index] < nums2[nums2Index] {
                    nums = append(nums, nums1[nums1Index])
                    nums1Index++
                }else{
                     nums = append(nums, nums2[nums2Index])
                    nums2Index++
                }                

        }
        nums = append(nums, nums1[nums1Index:]...)
        nums = append(nums, nums2[nums2Index:]...)
    }else{
        nums = append(nums1, nums2...)
    }
    numsLen =  len(nums)
    // return float64(nums[2])
    midValue := 0.00
    mid := numsLen / 2
    if numsLen  % 2 == 0 {
        midValue = float64(nums[mid-1] + nums[mid]) / 2
    }else{
        midValue = float64(nums[mid])
    }
    return midValue
}


```