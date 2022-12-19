### 解题思路
其实就是比较某个字母的个数，当一个单词的某个字母的个数大于字母表的某个单词的个数，那么字母表就不能构成这个单词，嘿嘿。

### 代码

```c
int countCharacters(char ** words, int wordsSize, char * chars){
    int *charsArray = (int *)calloc(sizeof(int), 26);
    for (int i = 0; chars[i]; i++) {
        charsArray[chars[i]-'a']++;
    }
    int *oneWordArray = (int *)calloc(sizeof(int), 26);
    int result = 0;
    for (int i = 0; i < wordsSize; i++) {
        for (int j = 0; j < 26; j++) {
            oneWordArray[j] = 0;
        }
        char *oneWord = words[i];
        for (int j = 0; oneWord[j]; j++) {
            oneWordArray[oneWord[j]-'a']++;
        }
        int oneLength = 0;
        for (oneLength = 0; oneWord[oneLength]; oneLength++);
        bool isOk = true;
        for (int j = 0; j < 26; j++) {
            if (oneWordArray[j] > 0 && oneWordArray[j] > charsArray[j]) {
                isOk = false;
                break;
            }
        }
        if (isOk) {
            result+=oneLength;
        }
    }
    return result;
}
```