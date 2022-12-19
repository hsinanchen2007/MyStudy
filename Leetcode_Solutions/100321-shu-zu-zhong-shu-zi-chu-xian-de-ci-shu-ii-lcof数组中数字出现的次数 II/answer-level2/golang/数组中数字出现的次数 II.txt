### 解题思路
使用map计数，然后找出值为1的key即可。

### 代码

```golang
func singleNumber(nums []int) int {
    md := make(map[int]int)
    for _, v := range nums {
        md[v]++
    }

    for k, v := range md {
        if v == 1 {
            return k
        }
    }

    return -1
}
```