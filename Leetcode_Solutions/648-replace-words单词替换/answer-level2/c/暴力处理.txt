### 解题思路
暴力处理

### 代码

```c
char * findWordEnd(char * sentence) {
    int sentenceLen = strlen(sentence);
    for (int i = 0; i < sentenceLen + 1; i++) {
        if ((*(sentence + i) == '\0') || (*(sentence + i) == ' ')) {
            return sentence + i;
        }
    }

    return sentence;
}

char * replaceWords(char ** dict, int dictSize, char * sentence){
    
    int sentenceLength = strlen(sentence);

    for (int i = 0; i < dictSize; i++) {
        char* wordsStart = NULL;
        char* searchStart = sentence;
        do {
            wordsStart = strstr(searchStart, dict[i]);
            if (wordsStart == NULL) {
                break;
            }
            
            char * wordEnd = findWordEnd(wordsStart); 
            
            if ((wordsStart == searchStart) || (*(wordsStart - 1) == ' ')) {
                memmove(wordsStart + strlen(dict[i]), wordEnd, strlen(wordEnd) + 1);
                searchStart = wordsStart + strlen(dict[i]);
            } else {
                searchStart = wordEnd;
            }
        } while(wordsStart != NULL);
    }

    return sentence;
}
```