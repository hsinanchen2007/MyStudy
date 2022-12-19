### 解题思路
暴力遍历，熟悉下GO的标准库 strconv 和 strings 

### 代码

```golang
func getNoZeroIntegers(n int) []int {
    res := []int{}
    for a := 1; a < n; a++ {
        b := n - a
        stra,strb := strconv.Itoa(a), strconv.Itoa(b)
        if !strings.Contains(stra, "0") && !strings.Contains(strb, "0") {
            res = append(res, a, b)
            return res
        }
    }
    return res
}
```