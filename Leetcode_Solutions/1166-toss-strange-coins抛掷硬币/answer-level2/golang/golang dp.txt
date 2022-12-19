每个硬币有且仅有正反两种情况，那么我们只需要分别分析这两种情况。
`map[key]value` key 表示目前存在的正面的个数，value 表示对应的概率。
每次计算当前情况，只需要将 map 中所有的 key 拿出来计算即可 
```
func probabilityOfHeads(prob []float64, target int) float64 {
    m := map[int]float64{}
    m[0] = 1 - prob[0]
    m[1] = prob[0]
    for i := 1; i < len(prob); i++ {
        m1 := map[int]float64{}
        for k, v := range m {
            if k + 1 <= target {
                m1[k + 1] += v * prob[i]
            }
            m1[k] += v * (1 - prob[i])
        }
        m = m1
    }
    return m[target]
}
```
