

typedef struct tagLinkNode {
    char *data;
    struct tagLinkNode *next;
} LinkNode;

typedef struct tagQueue {
    LinkNode *head;
    LinkNode *tail;
} Queue;
#define QUENUM 10000
int g_vist[QUENUM];
char *g_res[QUENUM];
int isQueueNull(Queue *que) 
{
    if (que->head == NULL) {
        return 1;
    }
    return 0;
}

int getQueueSize(Queue *que)
{
    LinkNode *curNode = que->head;
    int cnt = 0;
    if (isQueueNull(que)) {
        return 0;
    }    
    while (curNode != NULL) {
        cnt++;
        curNode = curNode->next;
    }
    return cnt;
}

void initQueue(Queue *que)
{
    que->head = que->tail = NULL;
}

void enQueue(Queue *que, char *data)
{
    LinkNode *newNode = calloc(1, sizeof(LinkNode));
    if (newNode == NULL) {
        return;
    }
    newNode->data = data;
    if (isQueueNull(que)) {
        que->head = que->tail = newNode;
        newNode->next = NULL;
    } else {
        que->tail->next = newNode;
        que->tail = newNode;
    }
    return;
}

void deQueue(Queue *que)
{
    LinkNode *head;
    if (isQueueNull(que)) {
        return;
    } else {
        head = que->head;
        que->head = que->head->next;
    }
    if (que->head == NULL) {
        que->tail = NULL;
    }
    free(head);
    head = NULL;
    return;
}

char* getQueueNodeVal(Queue *que)
{
    if (isQueueNull(que)) {
        return NULL;
    }
    return que->head->data;
}
int getNextRes(char **wordList, int wordListSize, char *src)
{
    int cnt = 0, i, j, k, diff, resFlag;
    for (i = 0; i < wordListSize; i++) {
        if (g_vist[i]) {
            continue;
        }
        j = 0;
        resFlag = 1;
        diff = 0;
        while(src[j] != '\0') {
            if (diff > 1) {
                resFlag = 0;
                break;
            }
            if (src[j] != wordList[i][j]) {
                diff++;
            }
            j++;
        }
        if (resFlag && diff == 1) {
            g_res[cnt++] = wordList[i];
            g_vist[i] = 1;
        }
    }
    return cnt;
}

void freeQueue(Queue *que)
{
    if (isQueueNull(que)) {
        return;
    }
    LinkNode *cur = que->head;
    LinkNode *next;
    while (cur) {
        next = cur->next;
        free(cur);
        cur = next;
    }
    que->head = que->tail = NULL;
}

int ladderLength(char * beginWord, char * endWord, char ** wordList, int wordListSize){
    int ans = 0, i, j, queSize, resCnt;
    Queue que;
    char *top;
    if (wordListSize == 0) {
        return 0;
    }
    initQueue(&que);
    memset(g_res, 0, sizeof(g_res));
    memset(g_vist, 0, sizeof(g_vist));
    enQueue(&que, beginWord);
    while(!isQueueNull(&que)) {
        queSize = getQueueSize(&que);
        ans++;
        for (i = 0; i < queSize; i++) {
            top = getQueueNodeVal(&que);
            deQueue(&que);
            if (strcmp(top, endWord) == 0) {
                freeQueue(&que);
                return ans;
            }            
            resCnt = getNextRes(wordList, wordListSize, top);
            for (j = 0; j < resCnt; j++) {
                enQueue(&que, g_res[j]);
            }
        }
    }
    freeQueue(&que);
    return 0;
}

