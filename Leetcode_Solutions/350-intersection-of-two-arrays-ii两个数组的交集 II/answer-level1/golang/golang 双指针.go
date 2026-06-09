![image.png](https://pic.leetcode-cn.com/c38afe8c8d69419493c252fdd209a234de2eb39ec001b73bc0ffbd1094cf5c2d-image.png)

```
func intersect(nums1 []int, nums2 []int) []int {
    var left,right int
    var res []int
    sort.Ints(nums1)
    sort.Ints(nums2)
    for left< len(nums1) && right < len(nums2){
        if nums1[left] == nums2[right] {
            res = append(res,nums1[left])
            left++
            right++
        }else if nums1[left] < nums2[right] {
            left++
        }else{
            right++
        }
    }
    return res
}
```
