### 解题思路
    内置库uthash.h提供的哈希表，双100%，C实现就是代码量太大了，简单题没必要。

### 代码

```c
typedef struct {
    int key;
    char* val;
    UT_hash_handle hh;
} entry;

char** SplitStr(char* s, int* size)
{
    *size = 1;
    int index = 0;
    while (s[index] != '\0') {
        if (s[index] == ' ') {
            (*size)++;
        }
        index++;
    }
    char** ret = (char**)malloc(sizeof(char*) * (*size));
    int headIdx = 0;
    int copySize;
    int copyLen;
    int sLen = strlen(s);
    index = 0;
    for (int i = 0; i <= sLen; i++) {
        if (s[i] == ' ' || s[i] == '\0') {
            copyLen = i - headIdx + 1;
            copySize = sizeof(char) * copyLen;
            char* p = (char*)malloc(copySize);
            memcpy(p, &s[headIdx], copySize);
            p[copyLen - 1] = '\0';
            headIdx = i + 1;
            ret[index] = p;
            index++;
        }
    }
    return ret;
}

bool ContainsVal(entry** m, char* s)
{
    entry *currentEntry, *tmp;  
    HASH_ITER(hh, *m, currentEntry, tmp) {  
        if (strcmp(s, currentEntry->val) == 0) {
            return true;
        }
    }
    return false;
}

void DeleteHash(entry** m) {  
    entry *currentEntry, *tmp;  
    HASH_ITER(hh, *m, currentEntry, tmp) {  
        free(currentEntry->val);
        HASH_DEL(*m, currentEntry);
        free(currentEntry);
    }
    return;
} 

bool wordPattern(char * pattern, char * str){
    if (!pattern || !str) {
        return false;
    }
    int size;
    char** strArr = SplitStr(str, &size);
    if (size != strlen(pattern)) {
        return false;
    }
    entry* hashTable = NULL;
    entry* findK;
    int key;
    for (int i = 0; i < size; i++) {
        findK = NULL;
        key = pattern[i];
        HASH_FIND_INT(hashTable, &key, findK);
        if (!findK) {
            if (ContainsVal(&hashTable, strArr[i])) {
                return false;
            }
            entry* insert = (entry*)malloc(sizeof(entry));
            insert->key = key;
            int mallocSize = sizeof(char) * (strlen(strArr[i]) + 1);
            char* sInsert = (char*)malloc(mallocSize);
            memcpy(sInsert, strArr[i], mallocSize);
            insert->val = sInsert;
            HASH_ADD_INT(hashTable, key, insert);
        } else {
            if (strcmp(findK->val, strArr[i]) != 0) {
                return false;
            }
        }
    }
    DeleteHash(&hashTable);
    return true;
}
```