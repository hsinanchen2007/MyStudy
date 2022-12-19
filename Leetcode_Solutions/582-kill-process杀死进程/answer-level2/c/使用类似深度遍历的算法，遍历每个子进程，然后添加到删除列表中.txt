### 解题思路
1、对特殊值进行处理，例如：父进程是0的处理
2、将kill节点加入删除列表中
3、遍历父进程，查看kill节点相等情况下，子进程都有哪些，然后加入到删除列表
4、遍历删除列表的同时，就生成了删除节点

### 代码

```c
int GetPidIndex(int* pid, int pidSize, int val) {
    for (int i = 0; i < pidSize; i++) {
        if (pid[i] == val) {
            return i;
        }
    }
    return pidSize;
}

void AddKillList(int* pid, int pidSize, int* ppid, int ppidSize, int val,
    int *killList, int *killNum, bool *killFlag, int *first, int *firstNum) {
    int index;

    index = GetPidIndex(pid, pidSize, val);
    if (index >= pidSize) {
        return;
    }

    if (killFlag[index]) {
        return;
    }

    killFlag[index] = true;
    killList[*killNum] = val;
    *killNum = *killNum + 1;

    for (index = 0; index < pidSize; index++) {
        if (killFlag[index]) {
            continue;
        }

        if (ppid[index] == val) {
            first[*firstNum] = pid[index];
            *firstNum = *firstNum + 1;
        }
    }
    return;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* killProcess(int* pid, int pidSize, int* ppid, int ppidSize, int kill, int* returnSize){
    int *killList = NULL;
    bool *killFlag = NULL;
    int *first = NULL;
    int killIndex;
    int killNum = 0;
    int firstNum = 0;

    killList = (int *)malloc((pidSize + 1) * sizeof(int));
    killFlag = (bool *)malloc((pidSize + 1) * sizeof(bool));
    first = (int *)malloc((pidSize + 1) * sizeof(int));
    if ((killList == NULL) || (killFlag == NULL) || (first == NULL)) {
        *returnSize = 0;
        free(killList);
        free(killFlag);
        free(first);
        return NULL;
    }

    if (pidSize != ppidSize) {
        *returnSize = 0;
        free(killFlag);
        free(first);
        return killList;
    }

    killIndex = GetPidIndex(pid, pidSize, kill);
    if (killIndex == pidSize) {
        *returnSize = 0;
        free(killFlag);
        free(first);
        return killList;
    }
    
    if (ppid[killIndex] == 0) {
        memcpy(killList, pid, pidSize * sizeof(int));
        *returnSize = pidSize;
        return killList;
    }

    memset(killFlag, 0x0, (pidSize + 1) * sizeof(bool));
    first[firstNum++] = kill;

    for (int index = 0; index < firstNum; index++) {
        AddKillList(pid, pidSize, ppid, ppidSize, 
        first[index], killList, &killNum, killFlag, first, &firstNum);
    }

    *returnSize = killNum;
    free(killFlag);
    free(first);    
    return killList;
}
```