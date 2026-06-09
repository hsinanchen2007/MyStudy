C++0ms通过
先设置四个状态，改变矩阵存储的值来判断下一阶段的状态
class Solution {
public:
    //0 死-活
    //1 活-死
    //2 活-活
    //3 死-死
    int judge(vector<vector<int>>& board, int i, int j, int q)//判断该点周围点的状态和个数，返回阶段值
    {
        int a, b, c, d, n = 0;
        a = i - 1 < 0 ? i : (i - 1);
        b = i + 1 >= board.size() ? i : (i + 1);
        c = j - 1 < 0 ? j : (j - 1);
        d = j + 1 >= board[0].size() ? j : (j + 1);
        for (int k = a; k <= b; k++)
        {
            for (int l = c; l <= d; l++)
            {
                if (board[k][l] == 1 || board[k][l] == 2)
                {
                    n++;
                }
            }
        }
        if (q == 1 || q == 2)
        {
            n -= 1;
        }
        if (q == 1)
        {
            if (n == 2 || n == 3)
            {
                return 2;
            }
            else
            {
                return 1;
            }
        }
        else
        {
            if (n == 3)
                return 0;
            else
                return 3;
        }
    }//每一次judge都改变了值
    void gameOfLife(vector<vector<int>>& board) 
    {
        int n = 0;

        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                board[i][j] = judge(board, i, j, board[i][j]);
            }
        }
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (board[i][j] == 0)
                    board[i][j] = 1;
                else if (board[i][j] == 1)
                    board[i][j] = 0;
                else if (board[i][j] == 2)
                    board[i][j] = 1;
                else if (board[i][j] == 3)
                    board[i][j] = 0;
            }
        }
    }
};