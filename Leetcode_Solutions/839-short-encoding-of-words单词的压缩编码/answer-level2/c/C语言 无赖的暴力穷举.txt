```
#define MAX_SIZE 10000
int minimumLengthEncoding(char ** words, int wordsSize){
    int len[MAX_SIZE] = {0};
    for (int i = 0; i < wordsSize; i++) {
        len[i] = strlen(words[i]);
    }
    for (int i = 0; i < wordsSize; i++) {
        for (int j = i + 1; j < wordsSize; j++) {
            if (words[i] == NULL || words[j] == NULL) {
                continue;
            }
            if (len[i] >= len[j]) {
                char *tmp = strstr(words[i], words[j]);
                if (tmp != NULL && (tmp == words[i] + len[i] - len[j])) {
                    words[j] = NULL;
                }
            } else {
                char *tmp = strstr(words[j], words[i]);
                if (tmp != NULL && (tmp == words[j] + len[j] - len[i])) {
                    words[i] = NULL;
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < wordsSize; i++) {
        if (words[i] != NULL) {
            ans += len[i] + 1;
        }

    }
    return ans;
} 
```
