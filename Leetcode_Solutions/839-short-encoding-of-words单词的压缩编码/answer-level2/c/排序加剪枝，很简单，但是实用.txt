```
int Compare(const void *a, const void *b) {
    char** ca = (char**)a;
    char** cb = (char**)b;
    return strlen(*cb) > strlen(*ca);
}
int IsEndOf(char *s, char *end) {
    int end1 = strlen(s) - 1;
    int end2 = strlen(end) - 1;
    while(end2 >= 0) {
        if(s[end1] != end[end2]) {
            return 0;
        }
        end2--;
        end1--;
    }
    return 1;
}
int minimumLengthEncoding(char ** words, int wordsSize){
    if (wordsSize == 0) {
        return 0;
    }
    if (wordsSize == 1) {
        return strlen(words[0]) + 1;
    }
    qsort(words, wordsSize, sizeof(char*), Compare);
    
    int *marked = (int *)malloc(sizeof(int) * wordsSize);
    memset(marked, 0, sizeof(int) * wordsSize);
    int count = 0;
    for(int i = 0; i < wordsSize; i++) {
        printf("%s\n", words[i]);
        if (marked[i] == 0) {
            count += strlen(words[i]) + 1;
            marked[i] = 1;
            for(int j = i + 1; j < wordsSize; j++) {
                if (marked[j] == 0 && IsEndOf(words[i], words[j])) {
                    //count += strlen(words[j]) + 1;
                    marked[j] = 1;
                }
            }
        }
    }
    return count;
}


```
