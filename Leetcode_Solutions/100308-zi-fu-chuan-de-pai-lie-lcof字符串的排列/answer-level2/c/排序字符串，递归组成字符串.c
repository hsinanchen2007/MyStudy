### 解题思路
1 递归组成字符串，在组成字符串的时候，判断将要进行下一次迭代的字符串是否有重复，去重处理
2 要在递归的时候进行去重不太容易，可以先对字符串进行排序

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void sortedString(char *str, int length, int start , int end) {
    if ( !str || !length || start >= end) {
        return ;
    }
    
    int ts = start;
    int te = end;
    int sentinal = str[start];
    while (te > ts) {
        while (str[te] >= sentinal && te > ts) {
            te--;
        }
        while (str[ts] <= sentinal && ts < te) {
            ts++;
        }
        
        if (ts < te) {
            int tmp = str[ts];
            str[ts] = str[te];
            str[te] = tmp;
        }
        else {
            int tmp = str[ts];
            str[ts] = sentinal;
            str[start] = tmp;
        }
    }
    
    sortedString(str, length, start, ts-1);
    sortedString(str, length, ts+1, end);
}



int *arrayExcludeValue(int *array, int excludeValue, int arrayLength) {
    if (array == NULL || arrayLength == 0) {
        return NULL;
    }
    if (arrayLength == 1) {
        return NULL;
    }
    
    int *newArray = malloc(sizeof(int) * arrayLength-1);
    int index = 0;
    for (int i = 0; i< arrayLength; i++) {
        if (array[i] != excludeValue) {
            newArray[index++] = array[i];
        }
    }
    return newArray;
}


bool leftArrayRepeated(char* origins,int **repteadLeftArray,int repteadLeftArrayCount,int *serail, int serialLength) {
    if (serialLength == 0) {
        return false;
    }
    for (int i = 0; i < repteadLeftArrayCount; i++) {
         int *leftSerail= repteadLeftArray[i];
        bool currentSame = true;
         for (int j = 0; j< serialLength; j++) {
             currentSame = currentSame & (origins[leftSerail[j]-1] == origins[serail[j]-1]);
         }
        if (currentSame) {
            return true;
        }
    }
    return false;
}

void recurseMakeSerial(char *origins,int *currentArray, int currentCount, int *leftArray,int leftArrayCount, int *serialNumber, int **serailList, int serialLength)
{
    if (leftArray == NULL || leftArrayCount == 0) {
        return;
    }
    
    if (leftArrayCount == 1) {
        int *doneSerial = malloc(sizeof(int)*serialLength);
        memcpy(doneSerial, currentArray, sizeof(int)*serialLength);
        doneSerial[serialLength-1] = leftArray[0];
        serailList[*serialNumber] = doneSerial;
        *serialNumber = (*serialNumber+1);
        return;
    }
    
    int **usedNewLeftArray = malloc(sizeof(int *) *leftArrayCount);
    int repeatedLeftArrayCount = 0;
    for (int i = 0; i <leftArrayCount; i++) {
        
        int *newCurrentArray = malloc(sizeof(int)*serialLength);
        if (currentCount !=0) {
            memcpy(newCurrentArray, currentArray, sizeof(int)*serialLength);
        }
        newCurrentArray[currentCount] = leftArray[i];
        int *newLeftArray = arrayExcludeValue(leftArray, leftArray[i], leftArrayCount);
        bool hasRepeteadLeftArray = false;
       if (i == 0) {
           usedNewLeftArray[0] = newLeftArray;
           hasRepeteadLeftArray = false;
           repeatedLeftArrayCount++;
       }
       else {
           hasRepeteadLeftArray = leftArrayRepeated(origins,usedNewLeftArray, repeatedLeftArrayCount, newLeftArray, leftArrayCount-1);
           if (!hasRepeteadLeftArray) {
               usedNewLeftArray[repeatedLeftArrayCount++] = newLeftArray;
           }
       }
        
       if (!hasRepeteadLeftArray) {
            recurseMakeSerial(origins,newCurrentArray, currentCount+1, newLeftArray, leftArrayCount-1, serialNumber, serailList,  serialLength);
       }
    }
}



char** permutation(char* s, int* returnSize){
    
    int N = strlen(s);
    
    if (N == 0 || s == NULL) {
        *returnSize = 0;
        return NULL;
    }
    
    char *copyStr = malloc(sizeof(char) *(N+1));
    strcpy(copyStr, s);
    sortedString(copyStr, N, 0, N-1);
    
    int serialCount = 1;
    for (int i=N; i>0; i--) {
        serialCount *= i;
    }
    
    
    int **serialList = (int **)malloc(sizeof(int*) * serialCount);
    int *currentArray = malloc(sizeof(int) * N);
    int *leftArray = malloc(sizeof(int) *N);
    for (int i = 1; i<=N; i++) {
        leftArray[i-1] = i;
    }
    int serialNumber = 0;
    recurseMakeSerial(copyStr,currentArray, 0, leftArray, N, &serialNumber, serialList, N);
    *returnSize = serialNumber;
    char **strList = malloc(sizeof(char *)* serialCount);
    
    for (long i = 0; i< serialNumber; i++) {
        int *currentSerial = serialList[i];
        char *stringSerail = malloc(sizeof(char) *(N+1));
        for (int j = 0; j< N; j++) {
            stringSerail[j] = copyStr[currentSerial[j]-1];
        }
        stringSerail[N] = 0;
        strList[i] = stringSerail;
    }
    
    return strList;
}

```