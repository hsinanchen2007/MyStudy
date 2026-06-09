// dp[layer][N][N];
// 动态规划方程
// int dir[8][2] = {{-1,2},{-1,-2},{-2,1},{-2,-1},{1,2},{1,-2},{2,1},{2,-1}};
// dp[k][x][y] += dp[k - 1][x][y] * 0.125;
 double knightProbability(int N, int K, int r, int c) {
        double dp[2][25][25];
        int dir[8][2] = 
        {
            {-1,2},
            {-1,-2},
            {-2,1},
            {-2,-1},
            {1,2},
            {1,-2},
            {2,1},
            {2,-1},
        };
        
        memset(dp,0,sizeof(dp));
        dp[0][r][c] = 1;
        
        int activedNums[2][625];
        int activedN = 0;
        int calculatedN = 0;
        int layer = 0;
        activedNums[layer][activedN++] = (r << 16) | c;
        
        for(int k = 1 ; k <= K ; ++k)
        {
            int nextLayer = (layer + 1) % 2;
            auto& activeLayer = activedNums[layer];
            auto& calLayer = activedNums[nextLayer];
            auto& activeBoard = dp[layer];
            auto& calBoard = dp[nextLayer];
            
            for(int ai = 0; ai < activedN; ++ai)
            {
                int i = activeLayer[ai] >> 16;
                int j = activeLayer[ai] & 0xFFFF;
                for(int m = 0 ; m < 8 ; ++m)
                {
                    int x = i + dir[m][0];
                    int y = j + dir[m][1];
                    if(x >= 0 && x < N && y >= 0 && y < N)
                    {
                        if(!(calBoard[x][y] > 0.00))
                        {
                            calLayer[calculatedN++] = (x << 16) | y;
                        }
                        calBoard[x][y] += activeBoard[i][j] * 0.125;
                    }
                }
            }
            
            memset(activeBoard,0,sizeof(activeBoard));
            activedN = calculatedN;
            calculatedN = 0;
            layer = nextLayer;
        }
        
        double result = 0.0;
        auto& activeBoard = dp[layer];
        for(int i = 0 ; i < N ; ++i)
        {
            for(int j = 0 ; j < N ; ++j)
            {
                result += activeBoard[i][j];
            }
        }
        
        return result;
    }
