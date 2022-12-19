### 解题思路
1 使用 100长的数组存储元素
2 从小到大遍历1-99符合条件的情况

### 代码

```c
#define MAX_LEN 100
#define DEC 10
#define DOUBLE 2

int g_DominoesNum[MAX_LEN] = { 0 };

int GetNum(int x)
{
    int m = x / DEC; // 10位
    int n = x % DEC; // 个位
    int y = n * DEC + m;    
    int xCnt = g_DominoesNum[x];
    int yCnt, cnt;

    // 如果没有记录
    if (xCnt == 0) {
        return xCnt;
    }

    yCnt = g_DominoesNum[y];

    if (y == x){
        yCnt = 0;
    } else if( x > y && yCnt > 0) {
        // 说明之前已经计算过
        return 0;
    }

    cnt = xCnt + yCnt;
    return cnt * (cnt - 1) / DOUBLE;
}

int numEquivDominoPairs(int** dominoes, int dominoesSize, int* dominoesColSize)
{
    int cnt = 0;
    int value;
    memset(g_DominoesNum, 0, sizeof(g_DominoesNum));
    for (int i = 0; i < dominoesSize; i++) {
        value = dominoes[i][0] * DEC + dominoes[i][1];
        g_DominoesNum[value]++;
    }

    for (int i = 0; i < MAX_LEN; i++) {
        cnt += GetNum(i);
    }

    return cnt;
}
```