### 解题思路
无脑暴力循环，看看其他高手怎么弄的

### 代码

```golang
func findRepeatNumber(nums []int) int {
    var m = make(map[int]bool)
    for _, ns := range nums {
        _, b := m[ns]
        fmt.Println(ns)
        if b {
            return ns
        }
        m[ns] = true
    }
    panic("未发现重复的数字")
}
```