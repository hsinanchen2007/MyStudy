```
func knightProbability(N int, K int, r int, c int) float64 {
    moves := [][]int{{-2, -1},{-2, 1},{-1, -2},{-1, 2},{1, -2},{1, 2},{2, -1},{2, 1}}
    temp, dp := make([][]float64, N), make([][]float64, N)
    for i := 0; i < N; i++ {
	temp[i], dp[i] = make([]float64, N), make([]float64, N)
	for j := 0; j < N; j++ {
	    dp[i][j] = 1
	}
    }
    for m := 1; m <= K; m++ {
	for i := 0; i < N; i++ {
	    for j := 0; j < N; j++ {
		for _, move := range moves {
		    nextX, nextY := i+move[0], j+move[1]
		    if nextX < 0 || nextX >= N || nextY < 0 || nextY >= N {
			continue
		    }
		    temp[i][j] += dp[nextX][nextY]
		}
		temp[i][j] /= 8
	    }
	}
	for i := 0; i < N; i++ {
	    for j := 0; j < N; j++ {
		dp[i][j], temp[i][j] = temp[i][j], 0
	    }
	}
    }
    return dp[r][c]
}
```
