```
#define MAX_NUM 200

int countCharacters(char ** words, int wordsSize, char * chars){
    int hash[MAX_NUM] = {0};
    int chLen = strlen(chars);
    int count = 0;
    for (int i=0;i<chLen;i++) {
        hash[chars[i]]++;
    }

    for (int i=0;i<wordsSize;i++) {
        int temp[MAX_NUM] = {0};
        memcpy(temp, hash, sizeof(int)*MAX_NUM);
        int flag = 1;
        int wordLen = strlen(words[i]);
        for (int j=0;j<wordLen;j++) {
            if (temp[words[i][j]] <= 0) {
                flag = 0;
                break;
            } else {
                temp[words[i][j]]--;
            }
        }

        if (flag) {
            count += wordLen;
        }
    }

    return count;
}
```
