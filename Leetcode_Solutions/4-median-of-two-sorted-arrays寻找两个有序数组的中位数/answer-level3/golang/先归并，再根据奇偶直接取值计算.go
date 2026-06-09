### 解题思路
此处撰写解题思路

### 代码

```golang
func findMedianSortedArrays(nums1 []int, nums2 []int) float64 {
    nums3 := combineSort(nums1,nums2)
    total := len(nums1)+len(nums2)
    if total%2 ==0 {
        return float64(nums3[total/2] + nums3[total/2-1])/2
    }else{
        return float64(nums3[total/2])
    }
}

func combineSort(a []int,b []int) []int{
    c := []int{}
    var i,j int 
    for i<len(a) && j<len(b) {
        if a[i]<=b[j] {
            c = append(c,a[i])
            i++
        } else {
            c = append(c,b[j])
            j++
        }
    }
    if i == len(a) {
        c = append(c , b[j:]...)
    } else{
        c = append(c,a[i:]...)
    }
    return c
}
```