### 解题思路
根据等差数列求和公式，转换成求首项公式，在生成结果就可以了

### 代码

```golang
func findContinuousSequence(target int) [][]int {
    // S = 1/2n^2 + (a1 - 1/2)n
    // a1 = (S - 1/2 n^2)/ n + 1/2
    res := make([][]int, 0)
    for n := float64(2); n < float64(target) / float64(2); n++ {
        a1 := (float64(target) - 0.5 * n * n) / n + 0.5
        if a1 == float64(int(a1)) && a1 > 0 {
            line := make([]int, 0, int(n))
            for i := 0; i < int(n); i++ {
                line = append(line, int(a1) + i)
            }
            res = append([][]int{line}, res...)
        }
    }
    return res
}
```