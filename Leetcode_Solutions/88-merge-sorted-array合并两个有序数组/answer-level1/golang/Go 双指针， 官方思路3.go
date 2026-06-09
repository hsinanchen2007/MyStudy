### 解题思路
Go 双指针， 官方思路3
O(m+n) O(1)
### 代码

```golang
func merge(nums1 []int, m int, nums2 []int, n int)  {
    p1, p2, p := m-1, n-1, m+n-1
    for p1 >=0 || p2 >= 0 {
        if p1 < 0 {
             nums1[p] = nums2[p2]
            p--
            p2--
        } else if p2 < 0 {
            nums1[p] = nums1[p1]
            p--
            p1--
        } else if  nums1[p1] < nums2[p2] {    //保证p1 ，p2都大于0
            nums1[p] = nums2[p2]
            p--
            p2--
        } else {
            nums1[p] = nums1[p1]
            p--
            p1--
        }
    }
}
```