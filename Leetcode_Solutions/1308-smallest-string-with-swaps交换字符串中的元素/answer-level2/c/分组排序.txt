typedef struct {
    int idx;
    int num;
    int* list;
}Node;

int compare(const void* a, const void* b) {
    return *(char*)a - *(char*)b;
}

int FindGroupIdx(int* groupIdx, int idx) {
    if (idx == groupIdx[idx]) {
        return idx;
    }
    else {
        groupIdx[idx] = FindGroupIdx(groupIdx, groupIdx[idx]);
        return groupIdx[idx];
    }
}

void AddGroup(int* groupIdx, int* groupNum, int* pairs) {
    int idx0 = FindGroupIdx(groupIdx, pairs[0]);
    int idx1 = FindGroupIdx(groupIdx, pairs[1]);

    if (idx0 > idx1) {
        groupIdx[idx0] = idx1;
        groupNum[idx1] += groupNum[idx0];
        groupNum[idx0] = 0;
    }
    else if (idx0 < idx1) {
        groupIdx[idx1] = idx0;
        groupNum[idx0] += groupNum[idx1];
        groupNum[idx1] = 0;
    }
}

void sortOneGroup(char* s, Node oneGroup) {
    char* charList;
    int i;

    charList = (char*)malloc(oneGroup.num);

    for (i = 0; i < oneGroup.num; i++) {
        charList[i] = s[oneGroup.list[i]];
    }

    qsort(charList, oneGroup.num, sizeof(char), compare);

    for (i = 0; i < oneGroup.num; i++) {
        s[oneGroup.list[i]] = charList[i];
    }

    free(charList);
}

char * smallestStringWithSwaps(char * s, int** pairs, int pairsSize, int* pairsColSize){
    int i,j;
    int* groupIdx;
    int* groupNum;
    Node* groupList;
    int groupCnt = 0; 
    int len = strlen(s);

    if (pairsSize == 0) {
        return s;
    } 

    groupIdx = (int*)malloc(len * sizeof(int));
    groupNum = (int*)malloc(len * sizeof(int));
    groupList = (Node*)malloc(len * sizeof(Node));

    for (i = 0; i < len; i++) {
        groupIdx[i] = i;
        groupNum[i] = 1;
    }

    for (i = 0; i < pairsSize; i++) {
        AddGroup(groupIdx, groupNum, pairs[i]);
    }

    for (i = 0; i < len; i++) {
        groupIdx[i] = FindGroupIdx(groupIdx, i);

        if (groupIdx[i] == i) {
            if (groupNum[i] > 1) {
                groupList[groupCnt].idx = i;
                groupList[groupCnt].num = 1;
                groupList[groupCnt].list = (int*)malloc(groupNum[i] * sizeof(int));
                groupList[groupCnt].list[0] = i;
                groupCnt++;
            }
        }
        else {
            for (j = 0; j < groupCnt; j++) {
                if (groupList[j].idx == groupIdx[i]) {
                    break;
                }
            }

            groupList[j].list[groupList[j].num] = i;
            groupList[j].num++;
        }
    }

    for (i = 0; i < groupCnt; i++) {
        sortOneGroup(s, groupList[i]);
        free(groupList[i].list);
    }

    free(groupList);
    free(groupIdx);
    free(groupNum);

    return s;
}