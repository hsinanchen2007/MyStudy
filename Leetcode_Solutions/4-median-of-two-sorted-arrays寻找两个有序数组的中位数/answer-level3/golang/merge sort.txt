```
func findMedianSortedArrays(nums1 []int, nums2 []int) float64 {
    if len(nums1) == 0 && len(nums2) == 0 {return 0}
    res := MergeSort(nums1, nums2)
    mid := len(res) / 2
    if len(res) % 2 == 0 {
        return float64((res[mid-1] + res[mid])) / 2
    } else {
        return float64(res[mid])
    }  
}


func MergeSort (num1, num2 []int) (res []int) {
    l , r := 0, 0
    for l < len(num1) && r < len(num2) {
        if num1[l] < num2[r] {
            res = append(res, num1[l])
            l++
        } else {
            res = append(res, num2[r])
            r++
        }
    }
    res = append(res, num1[l:]...)
    res = append(res, num2[r:]...)
    return
}
```
