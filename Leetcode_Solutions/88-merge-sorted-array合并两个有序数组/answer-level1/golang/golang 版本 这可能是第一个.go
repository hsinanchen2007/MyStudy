```go
/**
 1. 有序数组 立即想到 二分法,双指针 合并操作一般是双指针问题
 2. 从前向后想 需要辅助空间, 继续优化双指针问题人们容易忽视从后向前遍历
 3. 此题利用双指针从后向前遍历利用剩余空间存储结果,使空间复杂度降为常量
 4. 关键在于处理指针的边界问题 类似 (A) && (B) 这样的循环不变式 应该立即想到退出 循环有两种情况
    1) A 为false 则需要考虑B还为True的边界
    2) B 为fasle 则需要考虑A还为True的边界
 5. 对于 双数组的输入 一般需要考虑二者可能为空或者只有一两个元素的特殊CASE
*/
func merge(nums1 []int, m int, nums2 []int, n int)  {
    if len(nums1) == 0 || len(nums2) == 0 || n == 0{
        return
    }
    if m == 0{
       for i:=0;i < n;i++{
           nums1[i] = nums2[i]
       }
       return 
    }
    p, p1, p2 := m+n-1, m-1, n-1
    for p1 >= 0 && p2 >= 0{
        if nums1[p1] > nums2[p2]{
            nums1[p] = nums1[p1]
            p1 -- 
        }else{
            nums1[p] = nums2[p2]
            p2 --
        }
        p --
    }
    for p2 >= 0 && p >= 0{
        nums1[p] = nums2[p2]
        p  --
        p2 --
    }
}
```