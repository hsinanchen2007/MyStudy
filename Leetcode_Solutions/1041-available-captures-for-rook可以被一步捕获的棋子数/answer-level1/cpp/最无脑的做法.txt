第一步：找到 R 的位置

第二步：以R为中心向四个方向寻找B或p，如果是B（白象）就停止寻找，如果是p（黑卒）就加一并停止寻找

```
class Solution
{
public:
    int numRookCaptures(vector<vector<char>> &board)
    {
        int N = 8, i = 0, j = 0;

        // location the R
        for (int ii = 0; ii < N; ++ii)
        {
            for (int jj = 0; jj < N; ++jj)
            {
                if (board[ii][jj] == 'R')
                {
                    i = ii;
                    j = jj;
                    goto CAL;
                }
            }
        }

    CAL:
        // cal the num
        int ans = 0;
        for (int ii = i - 1; ii >= 0; --ii)
        {
            if (board[ii][j] == 'B')
            {
                break;
            }

            if (board[ii][j] == 'p')
            {
                ans++;
                break;
            }
        }

        for (int ii = i + 1; ii < N; ++ii)
        {
            if (board[ii][j] == 'B')
            {
                break;
            }

            if (board[ii][j] == 'p')
            {
                ans++;
                break;
            }
        }

        for (int jj = j - 1; jj >= 0; --jj)
        {
            if (board[i][jj] == 'B')
            {
                break;
            }

            if (board[i][jj] == 'p')
            {
                ans++;
                break;
            }
        }

        for (int jj = j + 1; jj < N; ++jj)
        {
            if (board[i][jj] == 'B')
            {
                break;
            }

            if (board[i][jj] == 'p')
            {
                ans++;
                break;
            }
        }

        return ans;
    }
};
```
