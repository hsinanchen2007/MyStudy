解题思路：
小时、分钟一共置位n, 分别获取小时、分钟置loop、(n-loop)位的可选列表，拼凑输出。

/* 测试置位 */
bool TestBit(int num, int bits)
{
    int count = 0;

    while(num) {
        if (num%2 == 1) {
            count++;
        }
        num = num/2;
    }

    if (count == bits) {
        return true;
    }

    return false;
}

/* 获取可选列表 */
void GetChoose(int *ItemArray, int *ItemNum, int ItemMax, int bits)
{
    int item;

    for (item = 0; item < ItemMax; item++) {
        if (TestBit(item, bits)) {
            ItemArray[(*ItemNum)++] = item;
        }
    }
    return;
}

#define MAX_ITEM 60         /* 分钟可选列表最大60，小时12 */
#define MAX_TOTAL (12 * 60) /* 最大全映射 */
#define ITME_LEN 6          /* xx:xx */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** readBinaryWatch(int num, int* returnSize)
{
    *returnSize = 0;
    char **retArray = (char **)malloc(sizeof(char *) * MAX_TOTAL);
    memset(retArray, NULL, (sizeof(char *) * MAX_TOTAL));

    int loop = 0;
    int hourArray[MAX_ITEM] = {0};
    int hourNum = 0;
    int minArray[MAX_ITEM] = {0};
    int minNum = 0;
    for (loop = 0; loop <= num; loop++) {               /* 小时/分钟一共num位 */
        hourNum = 0;
        memset(hourArray, 0, sizeof(hourArray));
        GetChoose(hourArray, &hourNum, 12, loop);       /* 获取小时的可选列表 */
        
        minNum = 0;
        memset(minArray, 0, sizeof(minArray));
        GetChoose(minArray, &minNum, 60, num - loop);   /* 获取分钟的可选列表 */

        int i;
        int j;
        for (i = 0; i < hourNum; i++) {
            for (j =0; j < minNum; j++) {
                retArray[*returnSize] = (char *)malloc(sizeof(char) * ITME_LEN);
                memset(retArray[*returnSize], 0, sizeof(char) * ITME_LEN);
                sprintf(retArray[*returnSize], "%d:%02d", hourArray[i], minArray[j]);
                (*returnSize)++;
            }
        }
    }

    return retArray;
}