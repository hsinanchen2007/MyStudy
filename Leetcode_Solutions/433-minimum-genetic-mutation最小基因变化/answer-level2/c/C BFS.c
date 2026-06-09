### 解题思路
1. BFS解决 和单词接龙 题目一模一样
2. 释放资源时，标记Flag；最后判断flag返回结果。

### 代码

```c
typedef struct {
    char *str;
    int level;
} Node;

bool IsDifferentOneChar(char *str1, char *str2, int len)
{
    if ((str1 == NULL) || (str2 == NULL)) {
        return false;
    }

    int diffNum = 0;
    for (int i = 0; i < len; i++) {
        if (str1[i] != str2[i]) {
            diffNum++;
        }
        if (diffNum > 1) {
            return false;
        }
    }

    return diffNum == 1;
}

// BFS
int minMutation(char * start, char * end, char ** bank, int bankSize)
{
    if ((start == NULL) || (end == NULL)) {
        return -1;
    }
    if ((bank == NULL) || (bankSize == 0)) {
        return -1;
    }

    int len = strlen(start);
    int front = 0;
    int rear = 0;

    Node* geneQueue = (Node *)malloc((bankSize + 2) * sizeof(Node)); // 保证队列不溢出
    if (geneQueue != NULL) {
        memset(geneQueue, 0, (bankSize + 2) * sizeof(Node));
    }

    int* flagArray = (int *)malloc(bankSize * sizeof(int)); // 是否入过队flag
    if (flagArray != NULL) {
        memset(flagArray, 0, bankSize * sizeof(int));
    }

    int i = 0;
    int resultLevel = 0;
    char* outStr = NULL;

    // start入队
    geneQueue[rear].level = 0;
    geneQueue[rear].str = start;
    rear++;
    bool isExist = false;

    // BFS
    while (front != rear) {
        // 元素出队，然后进行比较
        resultLevel = geneQueue[front].level;
        outStr = geneQueue[front].str;
        front++;

        if (strcmp(outStr, end) == 0) {
            isExist = true;
            break; // 符合要求，返回resultLevel
        }

        // 将符合条件的元素入队
        for (i = 0; i < bankSize; i++) {
            if (flagArray[i] == 0 && IsDifferentOneChar(bank[i], outStr, len)) {
                flagArray[i] = 1;
                geneQueue[rear].level = resultLevel + 1;
                geneQueue[rear].str = bank[i];
                rear++;
            }
        }
    }

    free(geneQueue);
    geneQueue = NULL;
    free(flagArray);
    flagArray = NULL;

    if (isExist) {
        return resultLevel;
    } else {
        return -1;
    }
}
```