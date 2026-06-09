### 解题思路

![image.png](https://pic.leetcode-cn.com/098a89ed8b211ab8d73268e4e33d13af842cff95ca6243d1f1414ac9d2645074-image.png)

### 代码

```c

#define MY_CHAR_SIZE 26
void procChars(char * chars, int charsCnt[MY_CHAR_SIZE])
{
    memset(charsCnt, 0x00, sizeof(int) * MY_CHAR_SIZE);
    while(*chars != '\0') {
        charsCnt[*chars - 'a']++;
        chars++;
    }
    return;
}
int procWord(char *word, int charsCnt[MY_CHAR_SIZE])
{
    int i, len;
    int localCharsCnt[MY_CHAR_SIZE];
    memcpy(localCharsCnt, charsCnt, sizeof(int) * MY_CHAR_SIZE);
    len = strlen(word);
    for (i = 0; i < len; i++) {
        if (localCharsCnt[word[i] - 'a'] == 0) {
            return 0;
        }
        localCharsCnt[word[i] - 'a']--;
    }
    return len;
}
int countCharacters(char ** words, int wordsSize, char * chars){
    int i;
    int rlt = 0;
    int charsCnt[MY_CHAR_SIZE];
    if (strlen(chars) == 0) {
        return 0;
    }
    procChars(chars, charsCnt);
    for (i = 0; i < wordsSize; i++) {
        rlt += procWord(words[i], charsCnt);
    }
    return rlt;
}
```