```
int min(int a, int b) {
    return (a < b ? a : b);
}
int shortestDistance(char ** words, int wordsSize, char * word1, char * word2){
    int * word1num = (int *) malloc(wordsSize * sizeof(int));
    memset(word1num, 0, wordsSize * sizeof(int));
    int * word2num = (int *) malloc(wordsSize * sizeof(int));
    memset(word2num, 0, wordsSize * sizeof(int));
    int word1Size = 0;
    int word2Size = 0;
    int res = 0;
    int min = INT_MAX;
    for(int i = 0; i < wordsSize; i++) {
        if(strcmp(words[i], word1) == 0) {
            word1num[word1Size++] = i;
        } 
        if(strcmp(words[i], word2) == 0) {
            word2num[word2Size++] = i;
        }
    }
    for(int i = 0; i < word1Size; i++) {
        for(int j = 0; j < word2Size; j++) {
            res = abs(word1num[i] - word2num[j]);
            if(res < min) {
                min = res;
            }
        }
    }
    free(word1num);
    free(word2num);
    return min;
}
```
