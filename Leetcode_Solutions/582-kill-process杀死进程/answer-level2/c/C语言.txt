### 解题思路
此处撰写解题思路

### 代码

```c
#define MAX(a, b) ((a) > (b) ? (a) : (b))
struct NodeInfo {
    int pid;
    int ppid;
    int childCnt;
    int *children;
};

void ShowMyChild(struct NodeInfo *process, int pid, int *ans, int *index)
{
    ans[(*index)++] = pid;
    for (int i = 0; i < process[pid].childCnt; i++) {
        ShowMyChild(process, process[pid].children[i], ans, index);
    }
}

void FreeMemory(struct NodeInfo *process, int processSize)
{
    for (int i = 0; i < processSize; i++) {
        if (process[i].children != NULL) {
            free(process[i].children);
            process[i].children = NULL;
        }
    }
    free(process);
    process = NULL;
}

int* killProcess(int* pid, int pidSize, int* ppid, int ppidSize, int kill, int* returnSize)
{
    int mallocSize;
    for (int i = 0; i < pidSize; i++) {
        mallocSize = MAX(mallocSize, pid[i]);
        mallocSize = MAX(mallocSize, ppid[i]);
    }
    mallocSize++;

    struct NodeInfo *process = (struct NodeInfo *)malloc(sizeof(struct NodeInfo) * mallocSize);
    for (int i = 0; i < mallocSize; i++) {
        process[i].pid = -1;
        process[i].ppid = -1;
        process[i].children = NULL;
        process[i].childCnt = 0;
    }

    /* 扫描PID和PPID，构建出树形队列 */
    for (int i = 0; i < pidSize; i++) {
        process[pid[i]].pid = pid[i];
        process[pid[i]].ppid = ppid[i];
        process[ppid[i]].pid =  ppid[i];
        process[process[pid[i]].ppid].childCnt++;
    }

    for (int i = 0; i < mallocSize; i++) {
        if (process[i].childCnt != 0) {
            process[i].children = (int *)malloc(sizeof(int) * process[i].childCnt);
            memset(process[i].children, 0, sizeof(int) * process[i].childCnt);
        }
        process[i].childCnt = 0;
    }

    for (int i = 0; i < pidSize; i++) {
        int parent = ppid[i];
        int curr = pid[i];
        int parentChild = process[parent].childCnt;
        process[parent].children[parentChild] = process[curr].pid;
        process[parent].childCnt++;
    }

    int *ans = (int *)malloc(sizeof(int) * mallocSize);
    memset(ans, 0, sizeof(int) * mallocSize);
    int index = 0;
    /* 找到对应的kill进程，返回 */
    for (int i = 0; i < mallocSize; i++) {
        if (process[i].pid == kill) {
            ShowMyChild(process, process[i].pid, ans, &index);
        }
    }

    FreeMemory(process, mallocSize);
    *returnSize = index;
    return ans;
}
```