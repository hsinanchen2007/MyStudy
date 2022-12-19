### 解题思路
此处撰写解题思路

### 代码

```c
int countCharacters(char ** words, int wordsSize, char * chars){
    if (words == NULL || wordsSize == 0 || chars == NULL) {
        return 0;
    }

    int *hash = (int*)malloc(sizeof(int) * 26);
    memset(hash, 0, sizeof(int) * 26);
    while (*chars != '\0') {
        hash[*chars - 'a']++;
        chars++;
    }

    int i = 0, j = 0, result = 0, flag;
    int k;
    int temp[26];
    while (i < wordsSize) {
        for (k = 0; k < 26; k++) {
            temp[k] = hash[k];
        }
        flag = 1;
        while (words[i][j] != '\0') {
            if (temp[words[i][j] - 'a']) {
                temp[words[i][j] - 'a']--;
            } else {
                flag = 0;
            }
            j++;
        }
        if (flag) {
            result += strlen(words[i]);
        }
        j = 0;
        i++;
    }
    free(hash);

    return result;
}
```