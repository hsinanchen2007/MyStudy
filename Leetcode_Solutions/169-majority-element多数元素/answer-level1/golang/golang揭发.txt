### 解题思路
使用map记录每个数字的出现次数，空间复杂度O(n)，时间复杂度O(n+m), m为不相同的数字个数

### 代码

```golang
func majorityElement(nums []int) int {
    cache := make(map[int]int, 0)
    for i := 0; i < len(nums); i++ {
        cache[nums[i]]++
    }
    for k, v := range cache {
        if v > len(nums)/2 {
            return k
        }
    }
    return -1
}
```