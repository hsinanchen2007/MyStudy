/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#define MAXSIZE 60000
int queue[MAXSIZE];
int head = 0, tail = 0;
void push(int data) {
    queue[head] = data;
    head = (head + 1) % MAXSIZE;
}

int pop() {
    int tmp = queue[tail];
    tail = (tail + 1) % MAXSIZE;
    return tmp;
}

int isEmpty() {
    return tail == head;
}

void initQue() {
    memset(queue, 0, sizeof(queue));
    head = 0;
    tail = 0;
}

typedef struct Node {
    int pid;
    struct Node *next;
}* ptrNode;

int* killProcess(int* pid, int pidSize, int* ppid, int ppidSize, int kill, int* returnSize){
    struct Node arry[MAXSIZE] = {{0, NULL}};
    ptrNode tmp = NULL;
    for (int i = 0; i < ppidSize; i++) {
        ptrNode childNode = malloc(sizeof(struct Node));
        childNode->pid = pid[i];
        childNode->next = NULL;
        arry[ppid[i]].pid =ppid[i];
        tmp = arry[ppid[i]].next;
        arry[ppid[i]].next = childNode;
        childNode->next = tmp;
    }

    int *retSet = malloc(sizeof(int) * MAXSIZE);
    memset(retSet, 0, sizeof(int) * MAXSIZE);
    *returnSize = 0;
    if (arry[kill].pid == kill) {
        initQue();
        push(kill);
        while (!isEmpty()) {
            int pid = pop();
            retSet[(*returnSize)++] = pid;
            tmp = arry[pid].next;
            while (tmp) {
                push(tmp->pid);
                tmp = tmp->next;
            }
        }
    } else {
        retSet[(*returnSize)++] = kill;
    }

    for (int i = 0; i < ppidSize; i++) {
        if (arry[ppid[i]].next) {
            tmp = arry[ppid[i]].next;
            arry[ppid[i]].next = arry[ppid[i]].next->next;
            free(tmp);
        }
    }
    return retSet;
}