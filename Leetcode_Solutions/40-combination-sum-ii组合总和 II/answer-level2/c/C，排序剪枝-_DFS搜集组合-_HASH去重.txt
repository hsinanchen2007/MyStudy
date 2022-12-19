### 解题思路
没太大难度，思路就看标题，这次比较仔细，一遍提交通过，写了1个半小时，速度还有待提升。

执行用时 :12 ms, 在所有 C 提交中击败了69.81%的用户内存消耗 :12.1 MB, 在所有 C 提交中击败了31.66%的用户
### 代码

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
struct myListNode{
    int* addr;
    int size;  
    struct myListNode* next;
};

bool hashNodeCmp(int* a, int aSize, int* b, int bSize){
    if (aSize != bSize){
        return false;
    }
    else{
        for (int i = 0; i <  aSize; i++){
            if (a[i] != b[i]){
                return false;
            }
        }

        return true;
    }
}

#define MAX_TABLE_SIZE  256
struct myListNode* hashTable[MAX_TABLE_SIZE] = {0};

int getHashIndex(int* a, int aSize){
    int hashIndex = 0;
    for (int i = 0; i < aSize; i++){
        hashIndex += a[i];
    }

    hashIndex = hashIndex % MAX_TABLE_SIZE;

    struct myListNode* hashNode = hashTable[hashIndex];

    if (NULL == hashNode){
        return hashIndex;
    }
    else{
        while (hashNode){
            if (true == hashNodeCmp(a, aSize, hashNode->addr, hashNode->size)){
                return -1;
            }
            hashNode = hashNode->next;
        }

        return hashIndex;
    }
}

struct myListNode* createHashNode(int* a, int aSize){
    struct myListNode* node = (struct myListNode*)malloc(sizeof(struct myListNode));
    node->addr = a;
    node->size = aSize;
    node->next = NULL;
    return node;
}

void insertHashNode(struct myListNode* node, int hashIndex){
    struct myListNode* hashNode = hashTable[hashIndex];

    if (NULL == hashNode){
        hashTable[hashIndex] = node;
        return; 
    }
    else{
        while (hashNode->next){
            hashNode = hashNode->next;
        }

        hashNode->next = node;
    }
}

void destroyHashTable(void){
    struct myListNode* freeNode = NULL;

    for (int i = 0; i < MAX_TABLE_SIZE; i++){
        struct myListNode* hashNode = hashTable[i];
        if (NULL == hashNode){
            continue;
        }
        else{
            while (hashNode){
                freeNode = hashNode;
                hashNode = hashNode->next;
                free(freeNode);
            }
        }
    }

    memset(hashTable, 0, sizeof(struct myListNode*) * MAX_TABLE_SIZE);
}

int** dupProc(int** aa, int* returnSize, int** returnColumnSizes){
    int index = 0;
    int lOk = 0;
    int* a = NULL;
    int* c = *returnColumnSizes;
    int aSize = *returnSize;
    int* cOk = (int*)malloc(sizeof(int) * (*returnSize));
    int** aaOk = (int**)malloc(sizeof(int*) * (*returnSize));

    memset(cOk, 0, sizeof(int) * (*returnSize));
    memset(aaOk, 0, sizeof(int*) * (*returnSize));

    for (int i = 0; i < aSize; i++){
        index = getHashIndex(aa[i], c[i]);
        if (-1 == index){
            continue;
        }

        insertHashNode(createHashNode(aa[i], c[i]), index);
        aaOk[lOk] = aa[i];
        cOk[lOk] = c[i];
        lOk++;
    }

    *returnSize = lOk;
    *returnColumnSizes = cOk;
    return aaOk;
}

int * addC(int* c, int l, int* c1, int l1){
    if (NULL == c){
        c = c1;
    }
    else{
        c = (int**)realloc(c, sizeof(int*) * (l + l1));
        memcpy(c + l, c1, sizeof(int) * l1);
    }
    return c;
} 
int ** addAA(int** aa, int l, int* a){
    if (NULL == aa){
        aa = (int**)malloc(sizeof(int*));
        *aa = a;
    }
    else{
        aa = (int**)realloc(aa, sizeof(int*) * (l + 1));
        aa[l] = a;
    }
    return aa;
}
int** dfs(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes, int pos){
    int i,j,k;
    int l = 0;
    int l1 = 0;
    int* c = NULL;
    int* c1 = NULL;
    int* a = NULL;
    int* a1 = NULL;
    int** aa = NULL;
    int** aa1 = NULL;

    //结束
    if (candidatesSize - 1 < pos){
        *returnSize = 0;
        return NULL;
    }

    //遍历
    for (i = pos; i < candidatesSize; i++){
        if (target == candidates[i]){
            c1 = (int*)malloc(sizeof(int));
            *c1 = 1;
            l1 = 1;
            c = addC(c, l, c1, l1);

            a = (int*)malloc(sizeof(int));
            *a =  candidates[i];
            aa = addAA(aa, l, a);

            l += l1;

            break;
        }
        else if (target > candidates[i]){
            aa1 = dfs(candidates, candidatesSize, target - candidates[i], &l1, &c1, i + 1);
            if (NULL != aa1){
                for (j = 0; j < l1; j++){//add itself
                    a1 = aa1[j];
                    a1 = realloc(a1, sizeof(int) * (c1[j] + 1));
                    a1[c1[j]] = candidates[i];
                    aa1[j] = a1;
                    c1[j] += 1;
                }
                c = addC(c, l, c1, l1);

                for (j = 0; j < l1; j++){
                    aa = addAA(aa, l, aa1[j]);
                    l += 1;
                }
            }
        }
        else{
            break;
        }
    }

    *returnColumnSizes = c;
    *returnSize = l;
    return aa;
}
int cmp(const void*a, const void*b){
    return *(int*)a - *(int*)b;
} 
int** combinationSum2(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes){
    int i,j,k;
    int l = 0;
    int l1 = 0;
    int* c = NULL;
    int* c1 = NULL;
    int* a = NULL;
    int* a1 = NULL;
    int** aa = NULL;
    int** aa1 = NULL;

    if (0 == candidatesSize){
        *returnSize = 0;
        return NULL;
    }

    qsort(candidates, candidatesSize, sizeof(int), cmp);

    if (target < candidates[0]){
        *returnSize = 0;
        return NULL;
    }

    //遍历
    for (i = 0; i < candidatesSize; i++){
        if (target == candidates[i]){
            c1 = (int*)malloc(sizeof(int));
            *c1 = 1;
            l1 = 1;
            c = addC(c, l, c1, l1);

            a = (int*)malloc(sizeof(int));
            *a =  candidates[i];
            aa = addAA(aa, l, a);

            l += l1;
        }
        else if (target > candidates[i]){
            aa1 = dfs(candidates, candidatesSize, target - candidates[i], &l1, &c1, i + 1);
            if (NULL != aa1){
                for (j = 0; j < l1; j++){//add itself
                    a1 = aa1[j];
                    a1 = realloc(a1, sizeof(int) * (c1[j] + 1));
                    a1[c1[j]] = candidates[i];
                    aa1[j] = a1;
                    c1[j] += 1;
                }
                c = addC(c, l, c1, l1);

                for (j = 0; j < l1; j++){
                    aa = addAA(aa, l, aa1[j]);
                    l += 1;
                }
            }
        }
        else{
            break;
        }
    }

    aa = dupProc(aa, &l, &c);

    destroyHashTable();

    *returnColumnSizes = c;
    *returnSize = l;
    return aa;
}
```