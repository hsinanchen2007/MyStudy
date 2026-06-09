
int GetStrLen(char *word, int wordlen, char *patternStr, char *strtemp)
{
    char targetchar[2] = {0};
    char *pos;
    int idx;
    for (idx = 0; idx < wordlen; idx++) {
        targetchar[0] = word[idx];
        pos = strstr(patternStr, targetchar);
        if (pos != NULL) {
            // patternStr 中去掉word字符串中的targetchar，patternStr剩下的字符串再继续匹配word的字符
            if (pos - patternStr == 0) {
                strcpy(strtemp, patternStr + 1);
                strcpy(patternStr, strtemp);
            } else {
                int diffPos = pos - patternStr;
                int i;
                int strLength = strlen(patternStr);
                for (i = diffPos; i < strLength; i++) {
                    patternStr[i] = patternStr[i + 1];
                }
                patternStr[strLength - 1] = 0;

            }
        } else {
            break;
        }
    }
    
    if (idx < wordlen) {
        return 0;
    } 

    return wordlen;
}

int isWordLearned(char *word, int wordlen, char *chars, int charslen)
{
    char *str = (char *)malloc(charslen + 1);
    if (str == NULL) {
        return 0;
    }
    memset(str, 0, sizeof(charslen + 1));
    strcpy(str, chars);

    char *strtemp = (char *)malloc(charslen + 1);
    if (strtemp == NULL) {
        return 0;
    }
    memset(strtemp, 0, sizeof(charslen + 1));

    int charCount = GetStrLen(word, wordlen, str, strtemp);
    free(str);
    free(strtemp);

    return charCount;
}

int countCharacters(char ** words, int wordsSize, char * chars){
    if (words == NULL || chars == NULL || wordsSize == 0) {
        return 0;
    }

    int i;
    int totallen = 0;
    int ret;
    for (i = 0; i < wordsSize; i++) {
        ret = isWordLearned(words[i], strlen(words[i]), chars, strlen(chars));
        totallen += ret;
    }

    return totallen;
}