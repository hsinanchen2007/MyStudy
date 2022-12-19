C语言，直接递归几行代码超时，用哈希提升下效率：

```c []
typedef struct {
    unsigned short cnt;
    unsigned short maxCnt;
    int *indexSet;
}RapidIndexHash;



void TravelKillProcess(int* pid, int pidSize, int* ppid, int ppidSize, int kill, int* returnSize, int *output, RapidIndexHash *hashIndex) {
    output[*returnSize] = kill;
    (*returnSize)++;

    if (hashIndex[kill].cnt == 0) {
        return;
    }

    for (int j = 0; j < hashIndex[kill].cnt; ++j) {
        TravelKillProcess(pid, pidSize, ppid, ppidSize, pid[hashIndex[kill].indexSet[j]], returnSize, output, hashIndex);
    }

    return;
}

void BuildHashIndex(int* pid, int pidSize, int* ppid, int ppidSize, RapidIndexHash *hashIndex, int maxHashIndex) {
    for (int i = 0; i < ppidSize; ++i) {
        if (ppid[i] > maxHashIndex) {
            continue;
        }

        if (hashIndex[ppid[i]].cnt == 0) {
            hashIndex[ppid[i]].maxCnt = 20;
            int memLen = sizeof(int) * hashIndex[ppid[i]].maxCnt;
            hashIndex[ppid[i]].indexSet = (int*)malloc(memLen);
            memset(hashIndex[ppid[i]].indexSet, 0, memLen);
            hashIndex[ppid[i]].indexSet[0] = i;
            hashIndex[ppid[i]].cnt++;
            continue;
        }

        if (hashIndex[ppid[i]].cnt != 0) {
            if (hashIndex[ppid[i]].cnt < hashIndex[ppid[i]].maxCnt) {
                hashIndex[ppid[i]].indexSet[hashIndex[ppid[i]].cnt] = i;
                hashIndex[ppid[i]].cnt++;
                continue;
            } else {
                int newMaxCnt = hashIndex[ppid[i]].maxCnt + 20;
                int newMemLen = sizeof(int) * (hashIndex[ppid[i]].maxCnt + 20);
                int *newHashIndex = (int*)malloc(newMemLen);
                memset(newHashIndex, 0, newMemLen);
                memcpy(newHashIndex, hashIndex[ppid[i]].indexSet, (hashIndex[ppid[i]].cnt * sizeof(int)));
                free(hashIndex[ppid[i]].indexSet);
                hashIndex[ppid[i]].indexSet = newHashIndex;
                hashIndex[ppid[i]].maxCnt = newMaxCnt;
                hashIndex[ppid[i]].indexSet[hashIndex[ppid[i]].cnt] = i;
                hashIndex[ppid[i]].cnt++;
            }
        }
    }
    return;
}

void FreeHashIndexMem(RapidIndexHash *hashIndex, int hashSize) {
    for (int i = 0; i < hashSize; ++i) {
        if (hashIndex[i].indexSet != NULL) {
            free(hashIndex[i].indexSet);
            hashIndex[i].indexSet = NULL;
        }
    }
}


int* killProcess(int* pid, int pidSize, int* ppid, int ppidSize, int kill, int* returnSize){
    int maxHashIndex = 100000;
    int hashIndexMemLen = sizeof(RapidIndexHash) * (maxHashIndex + 1);
    RapidIndexHash *hashIndex = (RapidIndexHash*)malloc(hashIndexMemLen);
    memset(hashIndex, 0, hashIndexMemLen);
    BuildHashIndex(pid, pidSize, ppid, ppidSize, hashIndex,  maxHashIndex);

    int outputMemLen = sizeof(int) * (pidSize + 1);
    int *output = (int*)malloc(outputMemLen);
    memset(output, 0, outputMemLen);
    *returnSize = 0;

    TravelKillProcess(pid, pidSize, ppid, ppidSize, kill, returnSize, output, hashIndex);
    FreeHashIndexMem(hashIndex, maxHashIndex + 1);
    free(hashIndex);
    return output;
}

