### 解题思路
使用map计数即可

### 代码

```golang
func singleNumbers(nums []int) []int {
    var ret []int
    md := make(map[int]int)
    for _, v := range nums {
        md[v]++
    }
    for k, v := range md {
        if v == 1 {
            ret = append(ret, k)
        }
    }
    return ret
}
```