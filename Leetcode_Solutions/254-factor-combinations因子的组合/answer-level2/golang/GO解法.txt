### 解题思路
执行用时 :
0 ms
, 在所有 Go 提交中击败了
100.00%
的用户
内存消耗 :
2 MB
, 在所有 Go 提交中击败了
66.67%
的用户

### 代码

```golang
var result [][]int

func getFactors(n int) [][]int {
    result = make([][]int, 0)

    recursive(n, make([]int, 0))

    return result
}

func recursive(n int, slices []int) {
    res := make([]int, 0)
    for i:=2; i<=int(math.Sqrt(float64(n))); i++ {
        if n%i == 0 {
            res = append(res, i)
        }
    }
    if len(res) == 0 {
        return
    }

    for _, v := range res {
        if len(slices) > 0 && slices[len(slices)-1] > v {
            continue
        }

        slices1 := make([]int, len(slices))
        copy(slices1, slices)
        slices1 = append(slices1, v, n/v)
        result = append(result, slices1)
        recursive(n/v, slices1[0:len(slices1)-1])
        //slices = slices[0:len(slices)-2]
    }
}
```