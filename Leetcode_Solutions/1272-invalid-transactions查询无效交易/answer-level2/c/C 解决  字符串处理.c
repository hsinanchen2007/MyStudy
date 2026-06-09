### 解题思路
1. C解决涉及字符串处理，很麻烦。定义交易数据结构体进行处理，定义数组并初始化；
2. 按2种判定方法进行判定，并记录无效的index；
3. 对原输入，按无效index申请空间，然后返回即可。

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define NUM_SIZE 10
#define SIZE 40

 typedef struct {
    int index;
    char name[NUM_SIZE];
    int time;
    int amount;
    char city[NUM_SIZE];
 } TransData;

int GetAbs(int a, int b)
{
    if (a >= b) {
        return a - b;
    }
    return b - a;
}

char ** invalidTransactions(char ** transactions, int transactionsSize, int* returnSize)
{
    if (transactions == NULL || transactionsSize == 0) {
        *returnSize = 0;
        return NULL;
    }

    // 1. 定义结构体数组，并初始化；字符串分割
    TransData* dataArray = (TransData*)malloc(transactionsSize * sizeof(TransData));

    int j = 0;
    char trans[SIZE] = {0};
    char *p;
    for (int i = 0; i < transactionsSize; i++) {
        dataArray[i].index = i;
        char *str[4];
        j = 0;
        memset(trans, 0, SIZE);
        strcpy(trans, transactions[i]); // 拷贝一条交易
        p = strtok(trans, ","); // 字符串分割
        while (p != NULL) {
            str[j] = p;
            j++;
            p = strtok(NULL, ",");
        }

        strcpy(dataArray[i].name, str[0]);
        dataArray[i].time = atoi(str[1]); // 字符串转int
        dataArray[i].amount = atoi(str[2]); // 字符串转int
        strcpy(dataArray[i].city,  str[3]);
    }

    // 2. 判断结构体数组 按2种无效判定方法
    int* inValidFlag = (int *)malloc(transactionsSize * sizeof(int)); // 标记是否无效交易  0 有效  1 无效
    if (inValidFlag != NULL) {
        memset(inValidFlag, 0, transactionsSize * sizeof(int));
    }

    for (int i = 0; i < transactionsSize; i++) {
        if (dataArray[i].amount > 1000) {
            inValidFlag[i] = 1; // 规则1 判定无效
        }

        for (int j = i + 1; j < transactionsSize; j++) {
            if (strcmp(dataArray[i].city, dataArray[j].city) && ! strcmp(dataArray[i].name, dataArray[j].name)) {
                if (GetAbs(dataArray[i].time, dataArray[j].time) <= 60) {
                    inValidFlag[i] = 1; // 规则2 判定无效
                    inValidFlag[j] = 1;
                }
            }
        }
    }

    // 3. 统计结果并输出
    int inValidCount = 0;
    for (int i = 0; i < transactionsSize; i++) {
        if (inValidFlag[i] == 1) {
            inValidCount++;
        }
    }

    *returnSize = inValidCount;
    char** result = (char **)malloc(inValidCount * sizeof(char*));
    if (result != NULL) {
        memset(result, 0, inValidCount * sizeof(char*));
    }

    int resultIndex = 0;
    for (int i = 0; i < transactionsSize; i++) {
        if (inValidFlag[i] == 1) {
            result[resultIndex] = (char *)malloc(SIZE * sizeof(char));
            if (result[resultIndex] != NULL) {
                memset(result[resultIndex], 0, SIZE * sizeof(char));
            }
            result[resultIndex] = transactions[i];
            resultIndex++;
        }
    }

    // 释放资源
    if (dataArray != NULL) {
        free(dataArray);
        dataArray = NULL;
    }
    if (inValidFlag != NULL) {
        free(inValidFlag);
        inValidFlag = NULL;
    }

    if (inValidCount > 0) {
        return result;
    }
    return  NULL;
}
```