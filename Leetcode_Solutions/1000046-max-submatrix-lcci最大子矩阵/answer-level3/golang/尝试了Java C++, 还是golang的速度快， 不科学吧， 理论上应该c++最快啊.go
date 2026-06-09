```go
func getMaxMatrix(matrix [][]int) []int {
    n := len(matrix)
    m := len(matrix[0])
    res := math.MinInt32
    var left, right, up, down int
    for i := 0; i < n; i++ {
        arr := make([]int, m)
        for j := i; j < n; j++ {
            combine(arr, matrix[j])
            sum := 0
            var l int
            for t, v := range arr {
                if sum < 0 {
                    sum = 0
                    l = t
                }
                sum += v
                if res < sum {
                    res = sum
                    left, right, up, down = l, t, i, j
                }
            }
        }
    }
    return []int {up, left, down, right}
}

func combine(arr1, arr2 []int) {
    for i, v := range arr2 {
		arr1[i] += v
	}
}

```