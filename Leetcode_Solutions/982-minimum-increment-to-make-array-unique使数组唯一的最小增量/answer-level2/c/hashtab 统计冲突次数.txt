### 解题思路
此处撰写解题思路

### 代码

```c
#define maxValue  40000

int minIncrementForUnique(int* A, int ASize){
    int moveCnt = 0;
    int *hashTbl = (int *)malloc(sizeof(int) * maxValue * 2);
    memset(hashTbl, 0, sizeof(int) * maxValue * 2);
    for (int i = 0; i < ASize; i++) {
        if (hashTbl[A[i]] != 0) {
            for(int j = 0; j < maxValue * 2; j++) {
                if (hashTbl[A[i] + j] == 0) {
                    hashTbl[A[i] + j] = 1;
                    break;
                }

                moveCnt++;
            }
        }
        hashTbl[A[i]] = 1;
    }
    return moveCnt;
}
```