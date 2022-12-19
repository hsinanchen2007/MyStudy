p1 初始化在数组1元素数量的尾部 m-1
p2 初始化在数组2元素数量的尾部 n-1
p  初始化在数组1长度的尾部 len(nums1)-1

- 方法：双指针移动，p1，p2较大元素，放入p处 ，并且维护对应指针。
- 终止条件：当p2 < 0,理由是当nums2的元素都被移动到nums1，即完成循环。
- 边界条件：当m = 0 时的处理
```
func merge(nums1 []int, m int, nums2 []int, n int)  {
    p1 := m-1
    p2 := n-1
    p := len(nums1)-1
    for p2>=0 {
        if p1 >=0 && nums1[p1] >= nums2[p2] {
            nums1[p] = nums1[p1]
            p1--
        }else{
            nums1[p] = nums2[p2]
            p2--
        }
        p--
    }
}
```
