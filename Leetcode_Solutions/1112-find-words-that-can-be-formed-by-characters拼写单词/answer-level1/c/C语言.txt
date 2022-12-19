
![image.png](https://pic.leetcode-cn.com/899964ce7a96cab6a462bb2432e8128fbb08e4551f2247a8625bbf58c75ee193-image.png)


```
int countCharacters(char ** words, int wordsSize, char * chars){
    int charNum[128]     = {0};
    int tempCharNum[128] = {0};
    int length           = 0;
    int wordLength       = 0;
    int i                = 0;
    int j                = 0;

    for (i = 0; chars[i] != '\0'; i++) {
        charNum[chars[i]] ++;
    }

    for (i = 0; i < wordsSize; i++) {
        wordLength = 0;
        memcpy(tempCharNum, charNum, sizeof(int) * 128);
        for (j = 0; words[i][j] != '\0'; j++) {
            if (tempCharNum[words[i][j]] > 0) {
                wordLength ++;
                tempCharNum[words[i][j]]--;
            } else {
                wordLength = 0;
                break;
            }
        }
        length += wordLength;
    }

    return length;
}
```

