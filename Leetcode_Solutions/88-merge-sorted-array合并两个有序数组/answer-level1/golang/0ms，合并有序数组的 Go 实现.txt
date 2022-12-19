![image.png](https://pic.leetcode-cn.com/6557e1e46b801714c411d8da4518ef6b6f8cdd1df5b613c8e73ada3e5c062932-image.png)

用了两种方法，第二种方法略微提速。

不知道为什么原地合并反而消耗空间多呢？

另外，append 超出容量会重新申请底层数组的坑，需要注意一下

方法一：原地合并，每次插入需要将数组后移（4ms，4.5MB）
```
func Insert(nums1 []int, i int, x int) []int {
    t := append([]int{}, nums1[i:len(nums1)-1]...)  // 注意 append 之后的切片长度不要超过原长度，不然会申请新数组进行扩容，nums1 就不是原数组了
    nums1[i] = x
    nums1 = append(nums1[:i+1], t...)    // 每次插入需要将数组后移
    return nums1
}

func merge(nums1 []int, m int, nums2 []int, n int)  {
    i,j := 0,0
    for i<m && j<n {
        if nums2[j] < nums1[i] {  
            nums1 = Insert(nums1, i, nums2[j])  // 在 nums1 的 i 位置插入元素 nums2[j]
            m++
            j++
        }
        i++
    }
    if j<n {
        nums1 = append(nums1[:i], nums2[j:]...)
    }
}
```

方法二：借助额外数组存储合并后的数组，然后将内容覆盖到原数组（0ms，3.9MB）
```
func merge(nums1 []int, m int, nums2 []int, n int)  {
    nums3 := []int{}
    i,j := 0,0
    for i<m && j<n {
        if nums2[j] < nums1[i] {
            nums3 = append(nums3, nums2[j])
            j++
        } else {
            nums3 = append(nums3, nums1[i])
            i++
        }
    }
    if j < n {
        nums3 = append(nums3, nums2[j:]...)
    } else if i < m {
        nums3 = append(nums3, nums1[i:m]...)    // 注意要限制追加的长度，不然后面的覆盖操作会失败，因为超出长度会重新申请底层数组
    }
    nums1 = append(nums1[:0], nums3...)    // 将 nums3 中的内容拷贝到 nums1 中覆盖
}
```