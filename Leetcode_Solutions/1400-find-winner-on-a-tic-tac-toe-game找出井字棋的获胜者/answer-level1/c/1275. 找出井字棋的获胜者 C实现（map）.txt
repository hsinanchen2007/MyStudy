### 解题思路
        建两个map，0-2记录每行的个数，3-5记录每列的个数，7记录斜率为1的个数，8记录斜率为-1的个数，每放置一次棋子对个数进行一次判断，满3个则返回对应map的玩家
    ，填满棋盘为平局，棋盘有空位且为分出胜负则可继续。
        最后记得释放内存。

### 代码

```c
inline bool ContainsLine(int* map)
{
    for (int i = 0; i < 8; ++i) {
        if (map[i] == 3) {
            return true;
        }
    }
    return false;
}

char * tictactoe(int** moves, int movesSize, int* movesColSize){
    int* mapA = (int*)malloc(sizeof(int) * 8);
    int* mapB = (int*)malloc(sizeof(int) * 8);
    memset(mapA, 0, sizeof(int) * 8);
    memcpy(mapB, mapA, sizeof(int) * 8);
    for (int i = 0; i < movesSize; ++i) {
        if ((i & 0x1) == 0) {
            mapA[moves[i][0]]++;
            mapA[moves[i][1] + 3]++;
            if (moves[i][0] == moves[i][1]) {
                mapA[6]++;
            }
            if (moves[i][0] + moves[i][1] == 2) {
                mapA[7]++;
            }
        } else {
            mapB[moves[i][0]]++;
            mapB[moves[i][1] + 3]++;
            if (moves[i][0] == moves[i][1]) {
                mapB[6]++;
            }
            if (moves[i][0] + moves[i][1] == 2) {
                mapB[7]++;
            }
        }
        if (ContainsLine(mapA)) {
            free(mapA);
            free(mapB);
            return "A";
        }
        if (ContainsLine(mapB)) {
            free(mapA);
            free(mapB);
            return "B";
        }
        if (i == 8) {
            free(mapA);
            free(mapB);
            return "Draw";
        }
    }
    free(mapA);
    free(mapB);
    return "Pending";
}
```