### 解题思路
看不懂题，请看英文。
- 模拟就完事
### 代码

```golang
func countLargestGroup(n int) int {
    if n < 10 {
        return n
    }
    res := make([][]int, 45)
    for i := 1; i < 46; i++ {
        for j := 1; j <= n; j++{
            if getSum(j) == i {
                res[i] = append(res[i], j)
            }
        }  
    }
    ret := make([]int, n)
    for i := 1; i < len(res); i++{
        ret[len(res[i])]++
    }
    for i := n-1; i >= 0; i-- {
        if ret[i] != 0 {
            return ret[i]
        }
    }
    return 0
}

func getSum(n int) int {
    res := 0
    for n != 0 {
        res += n%10
        n = n / 10
    }
    return res
}
```