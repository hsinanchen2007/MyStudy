### 解题思路
依次检查n-k+1个滑动窗口，返回每个窗口内的最大值

### 代码

```golang
func maxSlidingWindow(nums []int, k int) []int {
    var result []int
    if len(nums)==0{
        return result
    }
    const INT_MAX = int(^uint(0) >> 1)
    const INT_MIN = ^INT_MAX
    for i := 0; i < len(nums)-k+1; i++ {
        max := INT_MIN
        for j:=i;j<i+k;j++{
            if max < nums[j]{
                max = nums[j]
            }
        }
        result = append(result,max)
    }
    return result
}
```