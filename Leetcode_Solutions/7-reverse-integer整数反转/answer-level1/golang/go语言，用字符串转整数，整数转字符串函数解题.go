### 解题思路
此处撰写解题思路

### 代码

```golang
func reverse(x int) int {
    if x > 2147483647 || x < - 2147483648 {
        return 0
    }
    var result string
    var cur int
    if x < 0 {
        cur = - x
    }else {
        cur = x
    }
    for {
        result = result + strconv.Itoa(cur % 10)
        cur = cur / 10
        if cur == 0 {
            break
        }
    }
    res, _ := strconv.Atoi(result)
    if x < 0 {
        res = - res
    }
    if res > 2147483647 || res < - 2147483648 {
        return 0
    }
    return res
}
```