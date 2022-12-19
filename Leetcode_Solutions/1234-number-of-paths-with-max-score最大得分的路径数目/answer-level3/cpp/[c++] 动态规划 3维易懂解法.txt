先设置三维数组 **DP[边长][边长][2]** ,**DP[y][x][0]** 代表当前位置最大得分, **DP[y][x][1]** 代表可到达此点且得分相同的路径总数,

```
int step = 0;
// 左边,上边,左上 三条路径取最大值
int maxSum = max(DP[y - 1][x][0], max(DP[y][x - 1][0], DP[y - 1][x - 1][0]));
//如果与最大值相等,则增加路径数
if (DP[y - 1][x][0] == maxSum) step += DP[y - 1][x][1];
if (DP[y - 1][x - 1][0] == maxSum) step += DP[y - 1][x - 1][1];
if (DP[y][x - 1][0] == maxSum) step += DP[y][x - 1][1];
```
状态转移方程: 
**DP[y][x][0] = maxSum + board[y][x] - '0' ;
DP[y][x][1] = step;**
**若board[y][x] == 'X',则DP[y][x][0] = 0,DP[y][x][1] = 0.**

需单独判断`"EX","XS"`

```
class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string> &board) {
            //创建DP数组
            int DP[board.size()][board.size()][2];
            //初始化DP的第一行和第一列
            DP[0][0][0] = 0;
            DP[0][0][1] = 0;
            if (board[0][1] == 'X') {
                DP[0][1][0] = 0;
                DP[0][1][1] = 0;
            } else {
                DP[0][1][0] = board[0][1] - '0';
                DP[0][1][1] = 1;
            }
            if (board[1][0] == 'X') {
                DP[1][0][0] = 0;
                DP[1][0][1] = 0;
            } else {
                DP[1][0][0] = board[1][0] - '0';
                DP[1][0][1] = 1;
            }
            for (int y = 2; y < board.size(); y++) {
                if (DP[y - 1][0][0] == 0 || board[y][0] == 'X') {
                    DP[y][0][0] = 0;
                    DP[y][0][1] = 0;
                } else {
                    DP[y][0][0] = board[y][0] + DP[y - 1][0][0] - '0';
                    DP[y][0][1] = 1;
                }
            }
            for (int x = 2; x < board.size(); x++) {
                if (DP[0][x - 1][0] == 0 || board[0][x] == 'X'){
                    DP[0][x][0] = 0;
                    DP[0][x][1] = 0;
                } else{
                    DP[0][x][0] = DP[0][x - 1][0] + board[0][x] - '0';
                    DP[0][x][1] = 1;
                }
            }
            //初试完毕,直接打表
            for (int y = 1; y < board.size(); y++) {
                for (int x = 1; x < board.size(); x++) {
                    if (board[y][x] == 'X') {
                        DP[y][x][0] = 0;
                        DP[y][x][1] = 0;
                        continue;
                    }
                    int maxSum = max(DP[y - 1][x][0], max(DP[y][x - 1][0], DP[y - 1][x - 1][0]));
                    int step = 0;
                    if (maxSum != 0) {
                        if (DP[y - 1][x][0] == maxSum) step += DP[y - 1][x][1];
                        if (DP[y - 1][x - 1][0] == maxSum) step += DP[y - 1][x - 1][1];
                        if (DP[y][x - 1][0] == maxSum) step += DP[y][x - 1][1];
                        step %= 1000000007;
                        DP[y][x][0] = maxSum + board[y][x] - '0';
                        DP[y][x][1] = step;
                    } else{
                        DP[y][x][0] = 0;
                        DP[y][x][1] = 0;
                    }
                    if (board[y][x] == 'S') {
                        if (board.size() == 2 && maxSum == 0){
                            return vector<int>{0, 1};
                        } else{
                            return vector<int>{maxSum, step};
                        }
                    }
                }
            }
            return vector<int>{0, 0};
        }
};
```
