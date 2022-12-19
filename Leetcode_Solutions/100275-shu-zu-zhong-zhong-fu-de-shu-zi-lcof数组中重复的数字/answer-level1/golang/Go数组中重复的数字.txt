### 解题思路
遍历数组，先判断map中是否存在这个数，存在则返回否则将它写入map中。

### 代码

```golang
func findRepeatNumber (nums []int) int {
    duplicateMap := make(map[int]bool) 
    for _, v := range nums {
        if v < 0 || v >= len(nums) {
            return -1
        }
        // 可以在map中查重
        if  _, ok := duplicateMap[v]; ok { 
            return v
        }else {
            duplicateMap[v] = false
        }
    }
    return -1 
}
```