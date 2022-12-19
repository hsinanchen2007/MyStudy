### 解题思路
利用map的key的唯一性以及struct{}不占用内存的特性

### 代码

```golang
func findRepeatNumber(nums []int) int {
    if len(nums) == 0 {
        return -1
    }
    m := make(map[int]struct{})
    for _, num := range nums {
        if _, ok := m[num]; ok {
            return num
        } else {
            m[num] = struct{}{}
        }
    }
    return -1
}
```