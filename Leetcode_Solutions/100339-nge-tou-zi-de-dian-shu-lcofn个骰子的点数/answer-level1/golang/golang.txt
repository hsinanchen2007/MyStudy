```
func twoSum(n int) []float64 {
    t := n
    m := map[int]int{0:1}
    for t > 0 {
        m1 := map[int]int{}
        for i := 1; i <= 6; i++ {
            for k, v := range m {
                m1[k + i] += v
            }
        }
        m = m1
        t--
    }
    sum := 0
    for _, v := range m {
        sum += v
    }
    ret := make([]float64, n * 6 - n + 1)
    for k, v := range m {
        ret[k - n] = float64(v)/float64(sum)
    }
    return ret
}
```
