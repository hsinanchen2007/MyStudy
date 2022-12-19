### 解题思路
此处撰写解题思路
1. 字符串和单词按位编码，统计出字符个数；
2. 逐个单词进行字符个数比较，若满足条件则累加长度。

### 代码

```c
#define CHAR_ARRAY_SIZE 26

int countCharacters(char ** words, int wordsSize, char * chars)
{
    if (words == NULL || wordsSize == 0 || chars == NULL) {
        return 0;
    }

    int charArrayCnt[CHAR_ARRAY_SIZE] = {0};
    int len = strlen(chars);
    // chars按位编码
    for (int i = 0; i < len; i++) {
        int index = chars[i] - 'a';
        charArrayCnt[index]++;
    }

    int result = 0;
    for (int i = 0; i < wordsSize; i++) {
        int wordLen = strlen(words[i]);
        int wordArrayCnt[CHAR_ARRAY_SIZE] = {0};

        // word按位编码
        for (int j = 0; j < wordLen; j++) {
            int index = words[i][j] - 'a';
            wordArrayCnt[index]++;
        }

        // 字符个数比较
        bool canSpell = true;
        for (int k = 0; k < CHAR_ARRAY_SIZE; k++) {
            if (wordArrayCnt[k] > charArrayCnt[k]) {
                canSpell = false;
                break;
            }
        }

        if (canSpell) {
            result += wordLen;
        }
    }

    return result;
}
```