### 解题思路
本题要求时间复杂度在O(logn),需要用二分查找法。
二分查找的难点有两个：(一)边界条件。(二)对中值nums[mid]的处理。对于本题，如果nums[mid]>nums[mid+1]，说明峰值在mid左边(或就是mid)，否则，说明峰值在mid右边。通过这个结论可以调整left和right指针。因为本题需要借助nums[mid+1],这里会有超范围的嫌疑，由于循环条件是for left<right，没有=，所以mid永远小于right，所以在开区间内，可以存在mid+1，但不能存在mid-1。本题是借助二分查找的的搜索步骤，是则是不断夹逼的过程，退出循环的唯一条件是left=right。前一态是n-1,n。前两态是n-1,n,n+1。任何退出循环必定精力这两种状态，然后根据条件筛选出的唯一的值就是峰值。

### 代码

```golang
func findPeakElement(nums []int) int {
    if len(nums)<=0{
        return 0
    }

    left:=0
    right:=len(nums)-1
    mid:=0
    for left<right{
        mid=left+(right-left)/2

        if nums[mid]>nums[mid+1]{
            right=mid
        }else{
            left=mid+1
        }
    }

    return left
}
```