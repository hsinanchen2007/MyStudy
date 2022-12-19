### 解题思路
1、按照行号把预留的放在一起
2、根据判断输出当前行最多能做几个家庭（如果没有预留，正好2个家庭）

### 代码

```c
static int Compare(const void *a, const void *b)
{
    const int *pa = *(const int **)a;
    const int *pb = *(const int **)b;
    return (pa[0] == pb[0]) ? (pa[1] - pb[1]) : (pa[0] - pb[0]);
}

static int CalcReservedColNum(int** reservedSeats, int reservedSeatsSize)
{
    int res = 0;
    for (int i = 0; i < reservedSeatsSize; ) {
        int j;
        for (j = i + 1; j < reservedSeatsSize; j++) {
            if (reservedSeats[i][0] != reservedSeats[j][0]) {
                break;
            }
        }
        res++;
        i = j;
    }
    return res;
}

static int CalcCanSetHome(int *map, int mapSize)
{
    if (mapSize != 11) {
        return 0;
    }
    bool isTrue = false;
    isTrue = (map[2] == 0 && map[3] == 0 && map[4] == 0 && map[5] == 0 && map[6] == 0 && map[7] == 0 && map[8] == 0 &&
        map[9] == 0);
    if (isTrue) {
        return 2;
    }
    isTrue = (map[4] == 0 && map[5] == 0 && map[6] == 0 && map[7] == 0);
    if (isTrue) {
        return 1;
    }
    isTrue = (map[2] == 0 && map[3] == 0 && map[4] == 0 && map[5] == 0 &&
        (map[6] == 1 || map[7] == 1 || map[8] == 1 || map[9] == 1));
    if (isTrue) {
        return 1;
    }
    isTrue = ((map[2] == 1 || map[3] == 1 || map[4] == 1 || map[5] == 1) &&
        (map[6] == 0 && map[7] == 0 && map[8] == 0 && map[9] == 0));
    if (isTrue) {
        return 1;
    }

    return 0;
}

int maxNumberOfFamilies(int n, int** reservedSeats, int reservedSeatsSize, int* reservedSeatsColSize)
{
    int res;
    if (reservedSeatsSize == 0) {
        return 2 * n;
    }
    qsort(reservedSeats, reservedSeatsSize, sizeof(int *), Compare);

    res = 2 * (n - CalcReservedColNum(reservedSeats, reservedSeatsSize));
    for (int i = 0; i < reservedSeatsSize;) {
        int j;
        int map[11] = {0};
        map[reservedSeats[i][1]] = 1;
        for (j = i + 1; j < reservedSeatsSize; j++) {
            if (reservedSeats[i][0] != reservedSeats[j][0]) {
                break;
            }
            map[reservedSeats[j][1]] = 1;
        }
        res += CalcCanSetHome(map, 11);
        i = j;
    }
    return res;
}
```