### 解题思路
双指针查大小，将新加入的跟最大的比
### 代码

```golang
func maxSlidingWindow(nums []int, k int) []int {
    n := len(nums)
    if n == 0 {
        return nil
    }
    left, right := 0, k
    maxIdx := -1
    res := make([]int, 0)
    for i := 0; i < n-k+1; i++{
       if maxIdx < left{
           maxIdx = left + MaxIndx(nums[left:right], k)
        } else if nums[right-1] > nums[maxIdx]{
            maxIdx = right-1
        }
        res = append(res, nums[maxIdx])
        left++
        right++
    }
    return res
}

func MaxIndx(nums []int, k int) int {
    left, right := 0, k-1
    for left < right{
        if nums[left] > nums[right]{
            right--
        }else{
            left++
        }
    }
    return left
}
```