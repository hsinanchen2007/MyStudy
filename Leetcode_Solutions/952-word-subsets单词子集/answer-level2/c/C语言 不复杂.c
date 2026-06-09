搞两个26大小的字母表数组去比：
```
int arrayA[26] = {0};
int arrayB[26] = {0};

void calculateALetterNum(char* letter) {
    if (letter == NULL) {
        return;
    }
    int len = strlen(letter);
    for (int i = 0; i < len; i++) {
        arrayA[letter[i] - 'a'] += 1;
    }
    return;
}

void combineBString(char** string, int size) {
    int len = 0;
    int arrayC[26] = {0};
    char* combine = (char*)calloc(11, sizeof(char));
    
    for(int i = 0; i < size; i++) {
        memset(arrayC, 0, 26 * sizeof(int));
        memset(combine, 0, sizeof(char) * 11);
        memcpy(combine, string[i], strlen(string[i]));
        for (int j = 0; j < strlen(combine); j++) {
            arrayC[combine[j] - 'a'] += 1;
        }
        for (int k = 0; k < 26; k++) {
            if (arrayC[k] > arrayB[k]) {
                arrayB[k] = arrayC[k];
            }
        }
    }
    if (combine != NULL) {
        free(combine);
        combine = NULL;
    }
    return;
}

int ifAIncludeB(int* A, int* B) {
    int flg = 1;
    for (int i = 0; i < 26; i++) {
        if (B[i] > A[i]) {
            flg = 0;
        }
    }
    return flg;
}

char ** wordSubsets(char ** A, int ASize, char ** B, int BSize, int* returnSize){
    int k = 0;
    int ret = 0;
    *returnSize = 0;
    char** res = (char**)calloc(10000, sizeof(char*));

    memset(arrayB, 0, 26 * sizeof(int));
    combineBString(B, BSize);

    for (int i = 0; i < ASize; i++) {
        memset(arrayA, 0, 26 * sizeof(int));
        calculateALetterNum(A[i]);
        ret = ifAIncludeB(arrayA, arrayB);
        if (ret == 1) {
            res[k] = (char*)calloc(strlen(A[i]) + 1, sizeof(char));
            strcpy(res[k], A[i]);
            k++;
            (*returnSize)++;
        }
    }
    return res;
}
```
