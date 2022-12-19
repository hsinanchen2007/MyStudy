### 解题思路
此处撰写解题思路

### 代码

```golang
func knightProbability(N int, K int, r int, c int) float64 {
    return method_dp(N, K, r, c)
}

/*
定义三维dp[r][c][k], r,c表示棋盘上位置, k表示移动次数
设定dp[r][c][0] = 1, 即移动0次时概率是1

马走的8个坐标
{
    {-2, -1},
    {-2, 1},
    {-1, -2},
    {-1, 2},
    {1, -2},
    {1, 2},
    {2, -1},
    {2, 1},
}
依次计算移动1次时所有坐标的上概率， 再计算第二次移动 .... 直到第K次即为结果
dp[r][c][k] = dp[r-2][c-1][k-1] + .... dp[r-2][c-1][k-2] / 8
*/
func method_dp(N int, K int, r int, c int) float64 {
	steps := [][]int{
		{-2, -1},
		{-2, 1},
		{-1, -2},
		{-1, 2},
		{1, -2},
		{1, 2},
		{2, -1},
		{2, 1},
	}

	dp := make([][][]float64, N)
	for i := 0; i < N; i++ {
		dp[i] = make([][]float64, N)
		for j := 0; j < N; j++ {
			dp[i][j] = make([]float64, K+1)
		}
	}

	for m := 0; m <= K; m++ {
		for i := 0; i < N; i++ {
			for j := 0; j < N; j++ {
				if m == 0 {
					dp[i][j][0] = 1
				} else {
					for _, step := range steps {
						temp_i, temp_j := i+step[0], j+step[1]
						if temp_i < 0 || temp_i >= N || temp_j < 0 || temp_j >= N {
							continue
						}
						dp[i][j][m] += dp[temp_i][temp_j][m-1]
					}
					dp[i][j][m] /= 8
				}
				// fmt.Print(dp[i][j][m], " ")
			}
			// fmt.Println("")
		}
		// fmt.Println("")
	}

	return dp[r][c][K]
}

```