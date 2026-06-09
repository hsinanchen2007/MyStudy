### 解题思路
此处撰写解题思路

### 代码

```c

#define MAX_CHAR_NUM 27
int countCharacters(char ** words, int wordsSize, char * chars){
    if (words == NULL || chars == NULL) {
        return 0;
    }

    char charTable[MAX_CHAR_NUM] = {0};
    int i = 0, j = 0;
    int index = 0;
    int result = 0;
    
    while (chars[i] != '\0'){
        index = chars[i] - 'a';
        charTable[index]++; /* 记录字母表每个字母数量 */
        i++;
    }

    for (i = 0; i < wordsSize; i++) { /* 循环字符串数组，查看每个字母是否在字母表中存在 */
        j = 0;
        char tmp[MAX_CHAR_NUM] = {0};
        memcpy(tmp, charTable, sizeof(char) * MAX_CHAR_NUM);
        while(words[i][j] != '\0'){
            index = words[i][j] - 'a';
            if(tmp[index]== 0)
                break;
            tmp[index]--;
            j++;
        }

        if(words[i][j] == '\0') /* 内层循环结束，判断字符串是否都遍历完，遍历完代表能拼写*/
            result += j;
    }
    return result;
}

```