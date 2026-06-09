### 解题思路
使用 for range循环nums，然后将int转为string获取长度然后取模。

### 代码

```golang
func findNumbers(nums []int) int {
    var even int
    for _, v := range nums {
        if len(strconv.Itoa(v)) % 2 == 0 {
            even++
        }
    }
    return even
}
```