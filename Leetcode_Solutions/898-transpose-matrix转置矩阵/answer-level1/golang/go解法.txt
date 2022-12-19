func transpose(A [][]int) [][]int {
    var res [][]int
    for i := 0; i < len(A[0]); i++ {
        var temp []int
        for j := 0; j < len(A); j++ {
            temp = append(temp, A[j][i])
        }
        res = append(res, temp)
    }
    return res
}