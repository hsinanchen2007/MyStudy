### 解题思路
二分

### 代码

```golang
func missingNumber(nums []int) int {
    l, r := 0, len(nums)-1
    for l < r {
        mid := (l + r)/2
        if nums[mid] > mid {
            r = mid
        } else {
            l = mid + 1
        }
    }
    if nums[r] != r + 1{
        return r+1
    } else {
        return r
    }
}
```