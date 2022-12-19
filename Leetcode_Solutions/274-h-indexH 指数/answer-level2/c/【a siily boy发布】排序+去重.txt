```
int cmp(const void *a, const void *b) {
    return *(int *)b - *(int *)a;
}

int hIndex(int* citations, int citationsSize){
    int i;
    int j = 0;
    int **citCount;    
    int **citCountCpy;
    int returnValue = 0;
    int citIndex = 0;
    
    if ((citations == NULL) || (citationsSize == 0)) {
        return 0;
    }
    
    citCount = (int **)malloc(citationsSize * sizeof(int *));
    citCountCpy = (int **)malloc(citationsSize * sizeof(int *));
    for (i = 0; i < citationsSize; i++) {
        citCount[i] = (int *)malloc(2 * sizeof(int));
        citCountCpy[i] = (int *)malloc(2 * sizeof(int));
        for (j = 0; j < 2; j++) {
            citCount[i][j] = -1;
            citCountCpy[i][j] = -1;
        }
    }
    
    
    qsort(citations, citationsSize, sizeof(citations[0]), cmp);
    
    citCount[citIndex][0] = citations[0];
    citCount[citIndex][1] = 1;
    citCountCpy[citIndex][0] = citations[0];
    citCountCpy[citIndex][1] = 1;
    
    for (i = 1; i < citationsSize; i++) {
        if (citCount[citIndex][0] != citations[i]) {
            citIndex++;
            citCount[citIndex][0] = citations[i];
            citCount[citIndex][1] = citCount[citIndex - 1][1] + 1;
            
        } else {
            citCount[citIndex][1]++;
        }
    }
    
    /*
    printf("----------------------------------start-1\n");
    for (i = 0; i <= citIndex; i++) {
        printf("citCount[%u][0]: %d  citCount[%u][1]: %d\n", i, citCount[i][0], i, citCount[i][1]);
    }
    printf("citIndex: %d\n", citIndex);
    */
    
    j = 0;
    int tmpValue = 0;
    for (i = 0; i < citationsSize; i++) {
        tmpValue = citCount[j][0] ;
        //printf("i+1: %d, citCount[j][1]: %d\n", i + 1, citCount[j][1]);
        if ((i + 1) == citCount[j][1]) {
            citCountCpy[i][0] = citCount[j][0];
            citCountCpy[i][1] = citCount[j][1];  
            j++;
        } else {
            //printf("neibushixian: tmpValue: %u, (i + 1): %u\n", tmpValue, (i + 1));
            citCountCpy[i][0] = tmpValue;
            citCountCpy[i][1] = (i + 1);     
        }
    }
    /*
    printf("----------------------------------end-1\n");
    for (i = 0; i < citationsSize; i++) {
        printf("citCountCpy[%u][0]: %d  citCountCpy[%u][1]: %d\n", i, citCountCpy[i][0], i, citCountCpy[i][1]);
    }
    */

    for (i = citationsSize - 1; i >= 0; i--) {
        if (citCountCpy[i][1] <= citCountCpy[i][0]) {
           returnValue = citCountCpy[i][1];
            break;
        }
    }
    
    for (i = 0; i < citationsSize; i++) {
        free(citCount[i]); 
        free(citCountCpy[i]);
    }
    free(citCount);
    free(citCountCpy);
    return returnValue;
}
```
