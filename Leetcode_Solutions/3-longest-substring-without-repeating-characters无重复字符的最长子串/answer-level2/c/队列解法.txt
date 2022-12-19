### 解题思路
其实队列的思路很简单，从队列尾逐个插入字符数组的元数，每次插入遍历前面是否有相同的字符，若有就从队列头开始删除相同字符和之前的结点。
用maxlength来记录最大的队列长度。  

执行用时：28ms C提交中击败32.2%用户
内存消耗：10.8mb C提交中击败5.01%用户

时间复杂度O(n^2)
空间复杂度O(n)

惨不忍睹。
就想熟悉一下数据结构的那些内容

### 代码

```c
#define ERROR -1
#define OK 0

typedef struct QueueNode {
    char data;
    struct QueueNode* next;
}QueueNode;

typedef struct QueueList {
    QueueNode* head;
    QueueNode* tail;
    int length;
} QueueList;

int QueueEnter(QueueList* Q, char ch);
void InitQueueList(QueueList* Q);
int QueueItemIndex(QueueList Q, char ch);
int QueueDelet(QueueList* Q)

int lengthOfLongestSubstring(char* s) {
    if (s == NULL)return 0;

    int maxlength = 0;
    int i = 0;
    QueueList Q;
    InitQueueList(&Q);
    while (s[i] != '\0') {
        int index = QueueItemIndex(Q, s[i]);
        if (index != -1) {
            for (int i = 0; i < index; i++)
                QueueDelet(&Q);
        }
        QueueEnter(&Q, s[i]);
        if (Q.length > maxlength) maxlength = Q.length;
        i++;
    }
    return maxlength;
}

void InitQueueList(QueueList* Q) {//有头结点
    QueueNode* node = (QueueNode*)malloc(sizeof(QueueNode));
    node->next = NULL;
    Q->head = node;
    Q->tail = Q->head;
    Q->length = 0;
}

int QueueItemIndex(QueueList Q, char ch) {
    QueueNode* cur = Q.head->next;
    for (int i = 1; i <= Q.length; i++) {
        if (cur->data == ch)
            return i;
        cur = cur->next;
    }
    return -1;
}

int QueueEnter(QueueList* Q, char ch) {
    QueueNode* node = (QueueNode*)malloc(sizeof(QueueNode));
    node->data = ch;
    node->next = NULL;
    Q->tail->next = node;
    Q->tail = node;
    Q->length++;
    return OK;
}

int QueueDelet(QueueList* Q) {
    if (Q->head == Q->tail) return ERROR;
    QueueNode* temp = Q->head->next;
    Q->head->next = Q->head->next->next;
    Q->length--;
    if (Q->head->next == NULL) Q->tail = Q->head;
    free(temp);
    return OK;
}
```