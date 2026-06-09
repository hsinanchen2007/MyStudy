保存原始状态的方法很多，我这种反而是比较慢的

class Solution {
public:
    int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
    int dy[8] = {1, 0, -1, -1, -1, 0, 1, 1}; 
    int M = 0;
    int N = 0;
    void gameOfLife(vector<vector<int>>& board) {
        if(board.empty())
        {
            return;
        }

        M = board.size();
        N = board[0].size();
        for(int i = 0; i < M; ++i)
        {
            for(int j = 0; j < N; ++j)
            {
                int c = countLifeArround(board, i, j);
                
                // 0->1 ==> 2
                // 1->0 ==> 3
                if(board[i][j] == 1)
                {
                    if(c < 2 || c > 3)
                    {
                        board[i][j] = 3;
                    }
                }
                else
                {
                    if(c == 3)
                    {
                        board[i][j] = 2;
                    }
                }
            }
        }

        for(auto & v : board)
        {
            for(int & num : v)
            {
                if(num == 2)
                {
                    num = 1;
                }
                else if(num == 3)
                {
                    num = 0;
                }
            }
        }
    }


    int countLifeArround(vector<vector<int>>& board, int i, int j)
    {
        int res = 0;
        for(size_t k = 0; k < 8; ++k)
        {
            int x = i + dx[k];
            int y = j + dy[k];

            if(x >= 0 && x < M && y >= 0 && y < N)
            {
                if(board[x][y] % 2 == 1)
                {
                    res++;
                }
            }
        }

        return res;
    }
};
