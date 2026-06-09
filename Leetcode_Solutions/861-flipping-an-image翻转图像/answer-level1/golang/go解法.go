func flipAndInvertImage(A [][]int) [][]int {
    for x := 0; x < len(A); x++ {
        for i, j := 0, len(A[0]) - 1; i < j; i, j = i + 1, j - 1 {
            A[x][i], A[x][j] = A[x][j], A[x][i]
        }
        for y := 0; y < len(A[0]); y++ {
            if A[x][y] == 0 {
                A[x][y] = 1
            }else {
                A[x][y] = 0
            }
        }
    }
    return A   
}