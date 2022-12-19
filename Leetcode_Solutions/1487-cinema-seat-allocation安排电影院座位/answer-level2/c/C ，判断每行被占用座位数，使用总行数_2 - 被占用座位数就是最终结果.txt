### 解题思路
先排序，根据每一行已经预留的位置中间8bit对应占位情况，判断每行被占用的座位数。最后用总行数*2 - 被占用的座位数就是最终可以预定座位数

### 代码

```c
int cmp(void* a, void* b)
{
    int* a1 = *(int** )a;
    int* b1 = *(int** )b;
    if (a1[0] == b1[0]) {
        return a1[1] - b1[1];
    } else {
        return a1[0] - b1[0];
    }
}
int GetReservedNumSeatsEevryRow(unsigned char mask)
{
    int cnt;
    if ((mask & 0xff) == 0) {
        cnt = 2;
    } else if ((mask & 0xf) == 0 && (mask & 0xf0) != 0) {
         cnt = 1;
    } else if ((mask & 0xf0) == 0 && (mask & 0xf) != 0) {
        cnt = 1;
    } else if ((mask & 0x3c) == 0 && (mask & 0x03) != 0 && (mask & 0xc0) != 0) {
        cnt = 1;
    } else {
        cnt = 0;
    }
    return 2 - cnt;

}
int maxNumberOfFamilies(int n, int** reservedSeats, int reservedSeatsSize, int* reservedSeatsColSize){
    if ( n == 0) {
        return 0;
    }
    int numsCnt;
    int numTmp = 0;
    int i, j, k;
    int index = 0;
    unsigned char bitMask = 0;
    numsCnt = (n) * 2;
    qsort(reservedSeats, reservedSeatsSize, sizeof(reservedSeats[0]), cmp);
    int start = 0;
    int end = 0;
    for (start = 0; start < reservedSeatsSize; ) {
        while (end < reservedSeatsSize && reservedSeats[start][0] == reservedSeats[end][0]) {
            end++;
        }
        k = end - start;
        for (index = 0; index < k; index++) {
            if (reservedSeats[index + start][1] > 1 && reservedSeats[index + start][1] < 10) {
               bitMask = bitMask | ( 1 << (reservedSeats[index + start][1] - 2));

            }
        } 
        numTmp += GetReservedNumSeatsEevryRow(bitMask);
        bitMask = 0;
        start = end;
    }
    return (numsCnt - numTmp);

}
```