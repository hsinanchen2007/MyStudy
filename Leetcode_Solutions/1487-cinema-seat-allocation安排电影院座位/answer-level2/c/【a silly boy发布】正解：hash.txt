![139DC643-1475-44E2-8FE7-D38B9F606A82.jpeg](https://pic.leetcode-cn.com/a75683fd94fab43bd83e6733f19e80f6cd6f322d268db302c5c036a99a1d93b4-139DC643-1475-44E2-8FE7-D38B9F606A82.jpeg)

```
//使用hash存储
struct HashEntry {
    int key;
    int val;
    UT_hash_handle hh;
};

struct HashEntry *g_this;

int maxNumberOfFamilies(int n, int** reservedSeats, int reservedSeatsSize, int* reservedSeatsColSize){
    if (n == 0) {
        return 0;
    }
    if ((reservedSeats == NULL) || (reservedSeatsSize == 0) || (reservedSeatsColSize == NULL) || (*reservedSeatsColSize == 0)) {
        return 2 * n;
    }

    int i = 0;
    int level;
    int maxNum = 0;
    maxNum = 2 * n;
    struct HashEntry *tmpHashEntry;
    for (i = 0; i < reservedSeatsSize; i++) {
        level = reservedSeats[i][0];
        if ((reservedSeats[i][1] > 1) && (reservedSeats[i][1] < 10)) {
            HASH_FIND_INT(g_this, &level, tmpHashEntry);
            if (tmpHashEntry == NULL) {
                tmpHashEntry = (struct HashEntry*)malloc(sizeof(struct HashEntry));
                tmpHashEntry->key = level;
                tmpHashEntry->val = 0;
                tmpHashEntry->val |= 1 << (8 - reservedSeats[i][1] + 1);
                HASH_ADD_INT(g_this, key, tmpHashEntry);
                maxNum = maxNum - 2;
            } else {
                tmpHashEntry->val |= 1 << (8 - reservedSeats[i][1] + 1);
            }
        }
        //printf("key: %d, val: %d, maxNum: %d\n", reservedSeats[i][0], reservedSeats[i][1], maxNum);
    }
    int case1 = 0x0f;
    int case2 = 0xc3;
    int case3 = 0xf0;
    int case4 = 0x00;

    int returnVal = 0;
    int tmpCount;
    struct HashEntry *orderHashEntry = g_this;
    while (orderHashEntry != NULL) {
        //printf("key: %d, val: %d\n", orderHashEntry->key, orderHashEntry->val);
        if ((orderHashEntry->val | case4) == case4) {
            tmpCount = 2;
        } else if ((orderHashEntry->val | case1) == case1) {
            tmpCount = 1;
        } else if ((orderHashEntry->val | case2) == case2) {
            tmpCount = 1;
        } else if ((orderHashEntry->val | case3) == case3) {
            tmpCount = 1;
        } else {
            tmpCount = 0;
        }
        //printf("tmpCount: %d\n", tmpCount);
        returnVal = returnVal + tmpCount;
        orderHashEntry = orderHashEntry->hh.next;
    }
    struct HashEntry *currentHashEntry;
    struct HashEntry *tmp;
    HASH_ITER(hh, g_this, currentHashEntry, tmp) {
        HASH_DEL(g_this, currentHashEntry);
        free(currentHashEntry);
    }

    return returnVal + maxNum;
}
```
