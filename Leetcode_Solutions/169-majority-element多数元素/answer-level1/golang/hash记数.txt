### 解题思路
挺简单的，直接看代码吧

### 代码

```golang
func majorityElement(nums []int) int {
    mp := make(map[int]int)
    n := len(nums)
    result := 0
    for _, v := range nums {
        if _, ok := mp[v]; ok{
            mp[v]++
        } else {
            mp[v] = 1
        }
        if (mp[v]) > (n / 2) {
            result = v
        }
    }
    return result
}
```