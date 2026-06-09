```go
import "math"
func matrixBlockSum(mat [][]int, K int) [][]int {
    m := len(mat)
    n := len(mat[0])
    var result [][]int
    var k = K
    for i :=0; i < m; i++ {
        var tmp []int
        for j := 0; j< n; j++ {
            var sum int
            for ii := int(math.Max(0, float64(i-k))); ii <= int(math.Min(float64(i+k), float64(m-1))); ii ++ {
                for jj := int(math.Max(0, float64(j-k))); jj <= int(math.Min(float64(j+k), float64(n-1))); jj ++ {
                    sum += mat[ii][jj]
                }
            }
            tmp = append(tmp, sum)
        }
        result = append(result, tmp)
    }
    return result
}
```
