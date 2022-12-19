```C []
bool CheckPartOfStringIsOK(int *hashTable, int *checkWindow)
{
    for (int i = 'a'; i <= 'z'; ++i) {
        if ((checkWindow[i] != 0) && (checkWindow[i] != hashTable[i])) {
            return false;
        }
    }
    return true;
}


int* partitionLabels(char * S, int* returnSize){
    if (S == NULL) {
        *returnSize = 0;
        return NULL;
    }
    
    int hashTable[0x200] = {0};
    for (int i = 0; i < strlen(S); ++i) {
        hashTable[S[i]]++;
    }

    int memLen = (strlen(S) + 2) * sizeof(int);
    int *output = (int*)malloc(memLen);
    memset(output, 0, memLen);

    int checkWindMemLen = 0x200 * sizeof(int);
    int checkWindow[0x200] = {0};
    int cnt = 0;
    int outputCnt = 0;
    for (int j = 0; j < strlen(S); ++j) {
        cnt++;
        checkWindow[S[j]]++;
        if (CheckPartOfStringIsOK(hashTable, checkWindow) == true) {
            output[outputCnt] = cnt;
            outputCnt++;
            cnt = 0;
        }
    }
    *returnSize = outputCnt;
    return output;
}
```