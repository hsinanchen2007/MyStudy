### 解题思路
只有当短字符串和长字符串的后半部分相等时，才可以短字符串才能复用长字符串，如果和长字符串的前一部分相同时不能复用，明白这一点之后，把所有需要加入到S中的字符串放入一个字符串队列中，遍历所有字符串，如果在队列中找到了自己的父串就不需要加入队列，如果在队列中找到了自己的子串，就替换子串，如果没有找到和自己相关的字符串，就作为新成员在加入队列中，最后统计队列中所有字符串的长度加上对应#的个数就是结果了。

### 代码

```c
#define MAX_LEN 3000

typedef struct {
    int front;
    int tail;
    char words[MAX_LEN][8];
}Queue;

void checkQueue(Queue *q, char *word) 
{
    int len1, len2, result;
    int front = q->front;
    len1 = strlen(word);
    while (q->tail != front) {
        len2 = strlen(q->words[front]);
        if (len1 == len2) {
            if (0 == strcmp(word, q->words[front])) {
                return;
            } 
        } else if (len1 > len2) {
            if (0 == strcmp(word + len1 - len2, q->words[front])) {
                strncpy(q->words[front], word, len1);
                q->words[front][len1] = 0;
                return;
            } 
        } else {
            if (0 == strcmp(word, q->words[front] + len2 - len1)) {
                return;
            } 
        }
        front++;
    }
    strncpy(q->words[q->tail], word, len1);
    q->words[q->tail][len1] = 0;
    q->tail++;
    return;
}
int minimumLengthEncoding(char ** words, int wordsSize){
    if (words == NULL || wordsSize == 0) {
        return 0;
    }
    int i, j;
    int len = 0;
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->front = 0;
    q->tail = 0;
    strncpy(q->words[q->tail], words[0], strlen(words[0]));
    q->words[q->tail][strlen(words[0])] = 0;
    q->tail++;
    for (i = 1; i < wordsSize; i++) {
        checkQueue(q, words[i]);
    }
    while (q->tail != q->front) {
        len += (strlen(q->words[q->front++]) + 1); 
    }

    free(q);
    return len;
}

```