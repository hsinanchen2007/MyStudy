
动态规划：
与以下两题有类似之处：
62. 不同路径：https://leetcode-cn.com/problems/unique-paths/
799. 香槟塔 https://leetcode-cn.com/problems/champagne-tower/

对每一轮：
dp[i][j]:表示落到该点的概率；
dp[i][j] = sum(dp[i-move[0]][j-move[1]])  //move 表示8个方向的位移
1）第n轮的i，j点的概率等于从8个方向上到达该点的概率之和
2)每经历一轮，该点的概率之和需要除8；
3）加和时，需注意上一个点的坐标必须在地图内。


```cpp
class Solution {
public:
    vector<vector<int>> moves = {
        { 2, 1 }, { 2, -1 }, { 1, 2 }, { -1, 2 }, { -2, 1 }, { -2, -1 }, { 1, -2 }, { -1, -2 }
    };

    bool inArea(int r, int c, int N)
    {
        if (r >= 0 && r <= N - 1 && c >= 0 && c <= N - 1) {
            return true;
        }

        return false;
    }

    double knightProbability(int N, int K, int r, int c)
    {
        vector<vector<double>> dp = vector<vector<double>>(N, vector<double>(N, 0));
        double result = 0;
        dp[r][c] = 1;
        for (int i = 0; i < K; i++) {
            vector<vector<double>> tmpdp = dp;
            dp = vector<vector<double>>(N, vector<double>(N, 0));
            for (int j = 0; j < N; j++) {
                for (int l = 0; l < N; l++) {
                    for (auto move : moves) {
                        int prer = j - move[0];
                        int prec = l - move[1];
                        if (inArea(prer, prec, N)) {
                            dp[j][l]  += tmpdp[prer][prec];
                        }
                    }

                    dp[j][l] = dp[j][l] /8;
                }
            }

        }

        for (int i = 0; i < dp.size(); i++) {
            for (int j = 0; j < dp.size(); j++) {
                result += dp[i][j];
            }
        }

        return result;
    }
};
```
