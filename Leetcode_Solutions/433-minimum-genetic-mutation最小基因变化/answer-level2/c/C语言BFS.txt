typedef struct tagLinkNode {
    char *data;
    struct tagLinkNode *next;
} LinkNode;

typedef struct tagQueue {
    LinkNode *head;
    LinkNode *tail;
} Queue;
#define MMAX 10000
int g_visit[MMAX];
char *g_res[MMAX];
void initQueue(Queue *que)
{
    que->head = que->tail = NULL;
}
int isQueueNull(Queue *que)
{
    if (que->head == NULL) {
        return 1;
    }
    return 0;
}
int getQueueSize(Queue *que)
{
    int size = 0;
    LinkNode *node;
    if (isQueueNull(que)) {
        return 0;
    }
    node = que->head;
    while(node != NULL) {
        size++;
        node = node->next;
    }
    return size;
}
void pushQueue(Queue *que, char *data)
{
    LinkNode *newNode = calloc(1, sizeof(LinkNode));
    newNode->data = data;
    if (isQueueNull(que)) {
        que->tail = que->head = newNode;
    } else {
        que->tail->next = newNode;
        que->tail = newNode;
    }
}
void popQueue(Queue *que)
{
    LinkNode *node;
    if (isQueueNull(que)) {
        return;
    }
    node = que->head;
    que->head = que->head->next;
    free(node);
    node = NULL;
    if (que->head == NULL) {
        que->tail = NULL;
    }
    return;
}

char *getQueueVal(Queue *que)
{
    if(isQueueNull(que)) {
        return NULL;
    }
    return que->head->data;
}
int getNextRes(char **band, int bankSize, char *src)
{
    int cnt = 0, i, j, diff;
    for (i = 0; i < bankSize; i++) {
        if (g_visit[i] == 1) {
            continue;
        }
        j = 0;
        diff = 0;
        while (src[j] != '\0') {
            if (diff > 1) {
                break;
            }
            if (src[j] != band[i][j]) {
                diff++;
            }
            j++;
        }
        if (diff == 1) {
            g_res[cnt++] = band[i];
            g_visit[i] = 1;
        }
    }
    return cnt;
}

int minMutation(char * start, char * end, char ** bank, int bankSize){
    int i, j, ans = 0, queSize, resCnt;
    char *data;
    Queue que;
    if (bankSize == 0 || bank == NULL) {
        return -1;
    }
    memset(g_visit, 0, sizeof(g_visit));
    memset(g_res, 0, sizeof(g_res));
    initQueue(&que);
    pushQueue(&que, start);
    while (!isQueueNull(&que)) {
        ans++;
        queSize = getQueueSize(&que);
        for (i = 0; i < queSize; i++) {
            data = getQueueVal(&que);
            popQueue(&que);
            if (strcmp(data, end) == 0) {
                return ans-1;
            }            
            resCnt = getNextRes(bank, bankSize, data);
            for (j = 0; j < resCnt; j++) {
                pushQueue(&que, g_res[j]);
            }            
        }
       }
    return -1;
}