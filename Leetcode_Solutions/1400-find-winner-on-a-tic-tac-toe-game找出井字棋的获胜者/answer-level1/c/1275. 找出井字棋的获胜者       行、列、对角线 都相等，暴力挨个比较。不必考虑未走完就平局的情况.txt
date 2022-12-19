### 解题思路
A 和 B 在一个 3 x 3 的网格上玩井字棋。

井字棋游戏的规则如下：

玩家轮流将棋子放在空方格 (" ") 上。
第一个玩家 A 总是用 "X" 作为棋子，而第二个玩家 B 总是用 "O" 作为棋子。
"X" 和 "O" 只能放在空方格中，而不能放在已经被占用的方格上。
只要有 3 个相同的（非空）棋子排成一条直线（行、列、对角线）时，游戏结束。
如果所有方块都放满棋子（不为空），游戏也会结束。
游戏结束后，棋子无法再进行任何移动。
给你一个数组 moves，其中每个元素是大小为 2 的另一个数组（元素分别对应网格的行和列），它按照 A 和 B 的行动顺序（先 A 后 B）记录了两人各自的棋子位置。

如果游戏存在获胜者（A 或 B），就返回该游戏的获胜者；如果游戏以平局结束，则返回 "Draw"；如果仍会有行动（游戏未结束），则返回 "Pending"。

你可以假设 moves 都 有效（遵循井字棋规则），网格最初是空的，A 将先行动。

 

示例 1：

输入：moves = [[0,0],[2,0],[1,1],[2,1],[2,2]]
输出："A"
解释："A" 获胜，他总是先走。
"X  "    "X  "    "X  "    "X  "    "X  "
"   " -> "   " -> " X " -> " X " -> " X "
"   "    "O  "    "O  "    "OO "    "OOX"


### 代码

```c
char * tictactoe(int** moves, int movesSize, int* movesColSize) {
        int i, flag[3][3] = {0}, r, c, sum1, sum2;
        int row1, row2, row3, col1, col2, col3;
        char *res = malloc(16);

        memset(res, 0, 16);
       // memset(flag,0,9*sizeof(int));
        for (i = 0; i < movesSize; i++) {
            r = moves[i][0];
            c = moves[i][1];
            flag[r][c] = (i%2?4:1);
        }
        sum1 = flag[0][0] + flag[1][1] + flag[2][2];
        sum2 = flag[0][2] + flag[1][1] + flag[2][0];
        row1 = flag[0][0] + flag[0][1] + flag[0][2];
        row2 = flag[1][0] + flag[1][1] + flag[1][2];
        row3 = flag[2][0] + flag[2][1] + flag[2][2];
        col1 = flag[0][0] + flag[1][0] + flag[2][0];
        col2 = flag[0][1] + flag[1][1] + flag[2][1];
        col3 = flag[0][2] + flag[1][2] + flag[2][2];

        //printf("%d %d %d %d %d %d %d %d\n", sum1, sum2, row1, row2, row3, col1, col2, col3);
        if(sum1 == 3 || sum2 == 3 || row1==3 || row2==3 || row3==3 || col1==3 || col2==3 || col3==3){
            res[0] = 'A';
            return res;
        }
       if(sum1==12 || sum2==12 || row1==12 || row2==12 || row3==12 || col1==12 || col2==12 || col3==12){
            res[0] = 'B';
            return res;
        }
    
        if(movesSize < 9){
            sprintf(res,"Pending");
            return res;
        } else {
             sprintf(res,"Draw");
            return res;
        }
}
```