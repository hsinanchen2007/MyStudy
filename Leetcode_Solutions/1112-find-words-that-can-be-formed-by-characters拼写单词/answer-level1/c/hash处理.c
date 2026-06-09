### 解题思路
此处撰写解题思路

### 代码

```c
int countCharacters(char ** words, int wordsSize, char * chars){
    int hash[26] = { 0 };
    int tbl[26] = { 0 };
    int i, j;
    int totalLen = 0;
    bool flag;

    for (i = 0; i < strlen(chars); i++) {
        hash[chars[i] - 'a']++;
    }

    for (i = 0; i < wordsSize; i++) {
        flag = true;
        memset((void *)tbl, 0, sizeof(tbl));
        for (j = 0; j < strlen(words[i]); j++) {
            tbl[words[i][j] - 'a']++;
            if (tbl[words[i][j] - 'a'] > hash[words[i][j] - 'a']) {
                flag = false;
                break;
            }
        }

        if (flag == true) {
            totalLen += strlen(words[i]);
        }
    }
    return totalLen;
}
```