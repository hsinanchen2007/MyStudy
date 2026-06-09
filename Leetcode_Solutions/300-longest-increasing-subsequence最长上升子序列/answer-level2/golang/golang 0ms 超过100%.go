### 解题思路
此处撰写解题思路

### 代码

```golang
func lengthOfLIS(nums []int) int {
    var dp []int = make([]int, len(nums), len(nums))
    if len(nums) == 0 {return 0}
    var ret int
    // dp = initDp(dp, len(nums), 1)
    for _, value := range(nums) {
        index := findFirstLeast(dp, ret, value)
        dp[index] = value
        if index == ret {
            ret += 1
        }
    }
    return ret
}


func findFirstLeast(dp []int, ret int, value int) int {
   var start, end int = 0, ret
   mid := (start + end) / 2
   for {
       if start >= end {break}
       if dp[mid] < value {
           start = mid + 1
       } else {
           end = mid
       }
       mid = (start + end) / 2
   }
   return mid
}


```