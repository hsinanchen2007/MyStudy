![截屏2020-03-11下午10.20.06.png](https://pic.leetcode-cn.com/2c6c2274234c52f21f8369d478183ce04e5b02ac373fc04b31b95680f46b49cc-%E6%88%AA%E5%B1%8F2020-03-11%E4%B8%8B%E5%8D%8810.20.06.png)


### 代码

```golang
func largeGroupPositions(S string) [][]int {
    min := 0
    res := make([][]int, 0)
    for i,_ := range S {
        if i == len(S) - 1 || S[i] != S[i+1] {
            if i - min + 1 >= 3 {
                res = append(res, []int{min, i})
            }
            min = i + 1
        }
    }
    return res
}
```