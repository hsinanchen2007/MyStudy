执行用时 :0 ms, 在所有 golang 提交中击败了100.00%的用户
内存消耗 :3.6 MB, 在所有 golang 提交中击败了98.05%的用户

在学习归并排序的时候大家都知道在merge 的时候需要额外的一段空间对已经被分开的两端有序数组进行合并，与本题非常像。

所以我在想可不可以不多利用额外的空间就可以实现原地的两个数组排序呢？在这我使用 《编程珠玑》上提到的手摇算法，实现归并排序的原地排序。

不过本算法和上面各种大佬提到的并没有时间复杂度和空间复杂度的优势，借本题试一试比较新的算法。



贴代码如下：
```
func merge(nums1 []int, m int, nums2 []int, n int)  {
    for i, v := range nums2 {
        nums1[m+i] = v
    }
    if m == 0 || n == 0 {
        return 
    }
    i, j := 0, m
    for i < j && j<m+n {
        for i<m && nums1[i]<nums1[j] {
            i++
        }
        tmp := j
        for j<=m+n-1 && nums1[j]<=nums1[i] {
            j++
        }
        Convert(nums1, i, tmp, j-1)
        i = i+j-tmp+1
    }
}

func Convert(nums []int, left, middle, right int) {
    Reverse(nums, left, middle-1)
    Reverse(nums, middle, right)
    Reverse(nums, left, right)
}

func Reverse (nums []int, left, right int) {
    if left < right {
        for left < right {
            nums[left], nums[right] = nums[right], nums[left]
            left++
            right--
        }
    }
}

```

主要思路也比较明显：

1. func merge 主要是先将nums2 的元素搬移到nums1里，凑成可以实现手摇的结构。
2. 手摇部分：从前一段有序数组中找第一个大于后段数组的数字下标i，临时存储tmp=j，然后从后一段数组中找第一个大于前一段数组的下标新j，此时
i~tmp 均大于 tmp~j-1，所以可以对这段进行翻转
3. 翻转部分Reverse func & Convert func 则是进行翻转，做实验可得出要将i~tmp，tmp~j-1 进行翻转，则需要对i~tmp翻转一次，tmp~j-1翻转一次，再对i~j-1翻转一次 即完成任务。

空间复杂度：O(1) 未使用多余空间
平均时间复杂度：水平菜鸡，没算出来:( 求大佬指导

有不足和可以提升性能请告知~