![image.png](https://pic.leetcode-cn.com/6040be4babcd2e018897109cbb69bc5ec4eebdbfdbc78ac8e5e04d10aaf36be4-image.png)

开始想了个朴素的方法，就是用切片先生成最终结果数组，但是在 append 拼接过程中重新创建了底层数组，导致函数中的 nums 不再是函数外的 nums，引用失效。

所以乍一看没想到 O(1) 空间复杂度的解决办法，后来看到评论区的大佬的解决方案：

两种O(1)的方法，一种是做数组向右移动一位k次（也可以向移动操作少的方向移动），时间复杂度是O(kn)；另一种是reverse前半部分、后半部分、全部，这种方法时间复杂度是O(n)。

from 南宁：https://leetcode-cn.com/problems/rotate-array/comments/5344

**reverse前半部分、后半部分、全部**很巧妙呀，学习了~


方法一：朴素方法（128ms）

代码短，利用了语言的特性，用引用先生成了最终数组，时间复杂度还可以，但是空间复杂度达不到 O(1)
```
func rotate(nums []int, k int)  {
    k %= len(nums)
    ans := append(nums[len(nums)-k:], nums[:len(nums)-k]...)
    nums = append(nums[:0], ans...)
}
```

方法二：三次翻转（108ms）

reverse前半部分、后半部分、全部，时间复杂度是O(n)，空间复杂度 O(1)
```
func reverse(nums []int) {  // 翻转数组
    i,j := 0, len(nums)-1
    for i<j {
        nums[i],nums[j] = nums[j],nums[i]
        i++
        j--
    }
}

func rotate(nums []int, k int)  {
    k = k%len(nums)
    reverse(nums[:len(nums)-k])
    reverse(nums[len(nums)-k:])
    reverse(nums)
}
```