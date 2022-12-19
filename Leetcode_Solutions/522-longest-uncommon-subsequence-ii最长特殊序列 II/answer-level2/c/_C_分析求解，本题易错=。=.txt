### 解题思路
本题实际就是找不重复的最长子串（不被包含）
（1）使用散列先把所有字符存下来，并记录每个字符重复的个数，并记录最大字符串及其索引
（2）如果最大字符只重复1次则直接输出结果；
（3）将所有重复只有1次的（即无重复字符串），保存下来，用来后续进行查找比较；
（4）比较所有重复只有1次的串，与最大字符串进行比较，如果被包含则放弃；
（5）记录不被包含的最大的串（从重复只有1次的串中找即可），就是最终结果。
方法比较简单，需要自己理解下。

### 代码

```c
#define MAXS 60
typedef struct hashTableStruct {
    char *key[MAXS];
    int value[MAXS];
    int cnt;
}hastTableSt;
void initHashTable(hastTableSt *hashTmp)
{   
    int i;
    for (i = 0; i < MAXS; i++) {
        hashTmp->key[i] = NULL;
        hashTmp->value[i] = 0;
    }
    hashTmp->cnt = 0;
    return;
}

int findLUSlength(char ** strs, int strsSize){
    hastTableSt hashTmp;
    int i, j, k, flag, n;
    char *pMax[MAXS];
    char *pNoRep[MAXS];
    int idxMax, lenMax, len;
    int noRepCnt;
    int resultMax = -1;
    idxMax = 0;
    lenMax = 0;
    initHashTable(&hashTmp);
    // find all string and value
    for (i = 0; i < strsSize; i++) {
        flag = 0;
        len = strlen(strs[i]);
        if (len >= lenMax) {
            lenMax = len;
            idxMax = i;
        }
        for (j = 0; j < hashTmp.cnt; j++) {
            if (strcmp(hashTmp.key[j], strs[i]) == 0) {
                hashTmp.value[j]++;
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            hashTmp.key[hashTmp.cnt] = strdup(strs[i]);
            hashTmp.value[hashTmp.cnt] = 1;
            hashTmp.cnt++;
        }
    }
    // no repetition
    for (i = 0; i < hashTmp.cnt; i++) {
        if (strlen(hashTmp.key[i]) == lenMax && hashTmp.value[i] == 1) {
            return lenMax;
        }
    }

    // record the max one
    idxMax = 0;
    for (i = 0; i < hashTmp.cnt;  i++) {
        if (strlen(hashTmp.key[i]) == lenMax) {
            pMax[idxMax++] = strdup(hashTmp.key[i]);
        }
    }

    noRepCnt = 0;
    for (i = 0; i < hashTmp.cnt; i++) {
        if (hashTmp.value[i] == 1) {
            pNoRep[noRepCnt] = strdup(hashTmp.key[i]);
            noRepCnt++;
        }
    }
    // for (n = 0; n < idxMax; n++) {
    for (i = 0; i < noRepCnt; i++) {
        k = 0;
        flag = 0;
        len = strlen(pNoRep[i]);
        for (n = 0; n < idxMax; n++) {
            for (j = 0; j < strlen(pMax[n]); j++) {
                if (pNoRep[i][k] == pMax[n][j]) {
                    k++;
                    if (k >= len) {
                        break;
                    }
                }
            }
            if (k < len) {
                // is the result
                flag++;
            }
        }
        if (flag == idxMax) {
            if (len > resultMax) {
                resultMax = len;
            }
        }
        
    }
    
    return resultMax;

}
```