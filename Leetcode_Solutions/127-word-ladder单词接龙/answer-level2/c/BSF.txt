### 解题思路
1、看题目，寻找最优解，往广度搜索上想；
2、用队列实现广度搜索；
3、每一轮搜索，先找到搜索的范围，然后在这个范围内轮询一次，并将下一轮的节点加入队列；
4、先到达的先返回；

### 代码

```c


#define MAX_QUEUE_LEN 100000

int isSequ(char* a, char* b)
{
    int len = strlen(a);
    int i = 0;
    int count = 0;

    for (i = 0; i < len; i++) {
        if (*(a + i) != *(b + i)) {
            count++;
        }
    }
    return count == 1 ? true : false;
}
int ladderLength(char * beginWord, char * endWord, char ** wordList, int wordListSize){
    char* queueList[MAX_QUEUE_LEN] = {0};
    int head = 0;
    int tail = 0;
    int wordLen = strlen(beginWord);
    int i = 0;
    int j = 0;
    int find = 0;
    char* temp = NULL;
    int step = 1;
    int scop = 0;
    int* map = (int *)malloc(wordListSize * sizeof(int));
    memset(map, 0, wordListSize * sizeof(int));

    for (i = 0; i < wordListSize; i++) {
        if (strcmp(endWord, wordList[i]) == 0) {
            find = 1;
            break;
        }
    }
    if (find == 0) {
        free(map);
        return 0;
    }

    queueList[tail] = beginWord;
    tail++;

    while (head != tail) {
        scop = (tail - head + MAX_QUEUE_LEN) % MAX_QUEUE_LEN;

        for (i = 0; i < scop; i++) {
            temp = queueList[head];
            head = head + 1;
            if (strcmp(temp, endWord) == 0) {
                free(map);
                return step;
            }
            for (j = 0; j < wordListSize; j++) {
                if (map[j] == 0 && isSequ(temp, wordList[j])) {
                    map[j] = 1;
                    queueList[tail++] = wordList[j];
                }
            }
        }

        step++;
    }

    free(map);

    return 0;
}
```