bool is_canchange(char *src, char *dst) {
    int len1 = strlen(src);
    int lne2 = strlen(dst);

    if (len1 != lne2) {
        return false;
    }
    
    int cnt = 0;
    for (int i = 0; i < len1; i++) {
        if (src[i] != dst[i]) {
            cnt++;
        }

        if (cnt > 1) {
            break;
        }
    }

    return (cnt == 1) ? true : false;
}


#define LEN 10000

typedef struct {
    int step;
    char *pword;
} NODE;

typedef struct {
    int front;
    int rear;
    NODE node[LEN];
} QUEUE;

void init_queue(QUEUE *q) {
    q->front = 0;
    q->rear = 0;
}

bool qfull(QUEUE *q) {
    return (q->front + 1) % LEN  == q->rear;
}

bool qempty(QUEUE *q) {
    return q->front == q->rear;
}

void add_queue(QUEUE *q, NODE node) {
    q->node[q->front] = node;
    q->front = (q->front + 1) % LEN;
}

NODE del_queue(QUEUE *q) {
    NODE node = q->node[q->rear];
    q->rear = (q->rear + 1) % LEN;
    return node;
}

QUEUE g_queue;

int ladderLength(char * beginWord, char * endWord, char ** wordList, int wordListSize){
    bool *mask = (bool *)malloc(wordListSize * sizeof(bool));
    memset(mask, false, wordListSize * sizeof(bool));
    init_queue(&g_queue);
    
    bool findstart = false;
    bool findend = false;
    NODE tmpnode;
    for (int i = 0; i < wordListSize; i++) {
        if (is_canchange(beginWord, wordList[i])) {
            findstart = true;
        }

        if (strcmp(endWord, wordList[i]) == 0) {
            findend = true;
        }
    }

    if (findstart == false || findend == false) {
        return 0;
    }

    int min = 1000000;

    tmpnode.step = 1;
    tmpnode.pword = beginWord; 
    add_queue(&g_queue, tmpnode);

    while (!qempty(&g_queue)) {
        NODE node = del_queue(&g_queue);
        if (strcmp(node.pword, endWord) == 0) {
            min = min > node.step ? node.step : min;
            continue;
        }   

        for (int j = 0; j < wordListSize; j++) {
            if (mask[j] == false && is_canchange(node.pword, wordList[j])) {
                mask[j] = true;
                tmpnode.step = node.step + 1;
                tmpnode.pword = wordList[j];
                add_queue(&g_queue, tmpnode);
                //printf("step %d %s\n", tmpnode.step, wordList[j]);
            }
        }
    }
    
    return min;
}