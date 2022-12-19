### 解题思路
关键点是不能有重复数字，且最大最小数字之差不能大于4（不包含0）

### 代码

```golang
func isStraight(nums []int) bool {
    bucket := make([]bool,14)
    start := 14
    end := 0
    for _,val := range nums {
        if bucket[val] {
            return false
        }
        if !bucket[val] && val != 0 {
            bucket[val] = true
            if val < start {
                start = val
            }
            if val > end {
                end = val
            }
        }
    }
    if end - start > 4 {
        return false
    }
    return true
}
```