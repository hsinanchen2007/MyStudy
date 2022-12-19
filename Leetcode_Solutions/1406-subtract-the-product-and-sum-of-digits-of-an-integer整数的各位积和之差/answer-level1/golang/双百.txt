### 解题思路
把数字通过除10取余分解为不同十进制位上的数字同时进行求和与乘积，最后相减

### 代码

```golang
func subtractProductAndSum(n int) int {
    sum := 0
    prd := 1
    for n != 0 {
        sum += n%10
        prd *= n%10
        n = n / 10
    }
    return prd - sum
}
```