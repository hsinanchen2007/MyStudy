### 解题思路
利用每个下标的前缀和的差值找到最大字数组

### 代码

```golang
func maxSubArrayLen(nums []int, k int) int {
    // 前缀和
    // 利用每个下标的前缀和的差值找到最大字数组
    l := len(nums)
    var cache = make(map[int]int, 0)
    var sum = 0
    var res = 0

    for i := 0; i < l; i++ {
        sum += nums[i]
        // 从0下标开始到这个数正好和是k
        if sum == k {
            res = i + 1
        } else if key, ok := cache[sum - k]; ok {
            tmp := i - key
            if res < tmp {
                res = tmp
            }
        }
        // 判断是否已经有和相等的了
        if _, ok := cache[sum]; !ok {
            cache[sum] = i
        }
    }
    return res
}
```