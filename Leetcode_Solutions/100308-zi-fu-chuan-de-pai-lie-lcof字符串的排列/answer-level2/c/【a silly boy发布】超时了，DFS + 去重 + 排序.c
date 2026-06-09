![B22F3415-13F7-4D81-B7C0-61C2CD659E63.jpeg](https://pic.leetcode-cn.com/eb008e20b20a3a80fa83530f76b36107519fce481a7a1b4824881c8a69373756-B22F3415-13F7-4D81-B7C0-61C2CD659E63.jpeg)
```
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int sum = 0;

 bool IsSameElemet(char* s, int lenS, char **returnStr, int* returnSize)
 {
     bool returnValue = false;
     int i;
     for (i = 0; i < *returnSize; i++) {
         if (strcmp(s, returnStr[i]) == 0) {
             returnValue = true;
             return returnValue;
         }
     }

     return returnValue;
 }


void SubFuncDfs(char* s, int lenS, int index, char **returnStr, int* returnSize)
{
    char tmp;
    int i;
    bool isSameElemet = false;
    if (index == lenS - 1) {
        isSameElemet = IsSameElemet(s, lenS, returnStr, returnSize);
        if (isSameElemet == false) {
            strcpy(returnStr[*returnSize], s);
            (*returnSize)++;
        }
    } else {
        for (i = index; i < lenS; i++) {
            tmp = s[index];
            s[index] = s[i];
            s[i] = tmp;
            SubFuncDfs(s, lenS, index + 1, returnStr, returnSize);
            tmp = s[index];
            s[index] = s[i];
            s[i] = tmp;
        }
    }
}

int cmp(const void *a, const void *b) 
{
    int i;
    char *tmpA = *(int **)a;
    char *tmpB = *(int **)b;
    int returnValue;
    
    returnValue = strcmp(tmpA, tmpB);
    return returnValue;
}

char** permutation(char* s, int* returnSize){
    if (s == NULL) {
        *returnSize = 0;
        return NULL;
    }
    
    int lenS = strlen(s);
    sum = lenS;
    int index = 0;
    int mallocSize = 1;
    while (lenS != 1) {
        mallocSize = mallocSize * lenS;
        lenS = lenS - 1;
    }

    //printf("mallocSize: %d\n", mallocSize);
    int i;
    char **returnStr = (char **)malloc(mallocSize * sizeof(char *));
    for (i = 0; i < mallocSize; i++) {
        returnStr[i] = (char *)malloc((strlen(s) + 1) * sizeof(char));
    }
    *returnSize = 0;
    SubFuncDfs(s, strlen(s), index, returnStr, returnSize);

    qsort(returnStr, *returnSize, sizeof(returnStr[0]), cmp);

    return returnStr;
}
```
