### 解题思路
暴力解法，逐一比较，逐一合并处理，生成新的字符串数组，然后计算长度。

### 代码
```c
int minimumLengthEncoding(char ** words, int wordsSize){
    char str[2000][8] = {'\0'};
    bool handled[2000] = {false};  //字串是否被合并处理过
    char *tmp;
    int len = 0;

    for (int i = 0; i < wordsSize; i++) {
        if (handled[i]) {
            continue;    
        } else {
             strcpy(str[i], words[i]);
        }

        for (int j = i + 1; j < wordsSize; j++) {
            if (strlen(str[i]) >= strlen(words[j])) {
                tmp = str[i] + strlen(str[i]) - strlen(words[j]);
                if (!strncmp(tmp, words[j], strlen(words[j]))) {
                    handled[j] = true;
                } 
            } else {
                tmp = words[j] + strlen(words[j]) - strlen(str[i]);
                if (!strncmp(str[i], tmp, strlen(str[i]))) {
                    strcpy(str[i], words[j]);
                    handled[j] = true;
                }
            }
        }
        len = len + strlen(str[i]) + 1;
    }
    return len;
}

```