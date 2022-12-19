### 解题思路
重复元素，先用一个map统计每个元素出现次数，并得到非重复数组
然后顺序遍历每个数组元素，每个元素push 0到n次

### 代码

```golang
func pass(uniq []int, count []int, idx int, m *map[int]int, res *[][]int) {
    if idx >= len(uniq) {
        var subset []int
        for i, num := range uniq {
            for j := 0; j < count[i]; j++ {
                subset = append(subset, num)
            }
        }
        *res = append(*res, subset)
        return
    }

    for i := 0; i <= (*m)[uniq[idx]]; i++ {
        count[idx] = i
        pass(uniq, count, idx+1, m, res)
    } 
}

func subsetsWithDup(nums []int) [][]int {
    m := make(map[int]int)
    for _, n := range nums {
        m[n] += 1
    }
    uniq := make([]int, 0, len(m))
    for k := range m {
        uniq = append(uniq, k)
    }
    var res [][]int
    count := make([]int, len(uniq), len(uniq))
    pass(uniq, count, 0, &m, &res)
    return res   
}
```