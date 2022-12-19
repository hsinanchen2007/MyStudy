![image.png](https://pic.leetcode-cn.com/77e078acd3ae178261e1ca8d604b986e0cf7ce4fbc8c41afc003ff5ee8a8746a-image.png)

```
int cmp(const void *a, const void *b)
{
    return *(char *)a - *(char *)b;
}

bool IsHaveSameElement(char *words, char * chars)
{
    int cntWords = strlen(words);
    int cntChars = strlen(chars);
    int i;

    if (cntWords < cntWords) {
        return false;
    }
    int index = 0;
    for (i = 0; i < cntChars; i++) {
        if (words[index] == chars[i]) {
            index++;
            if (index == cntWords) {
                return true;
            }
        }
    }
    
    return false;
}

int countCharacters(char ** words, int wordsSize, char * chars)
{
    int i;
    int sum = 0;
    int returnValue = 0;
    bool isHaveSameElement;

    if ((words == NULL) || (wordsSize == 0)) {
        return 0;
    }
    if (chars == NULL) {
        return 0;
    }

    qsort(chars, strlen(chars), sizeof(chars[0]), cmp);
    for (i = 0; i < wordsSize; i++) {
        if (words[i] == NULL) {
            continue;
        }
        isHaveSameElement = false;
        qsort(words[i], strlen(words[i]), sizeof(words[0][0]), cmp);
        isHaveSameElement = IsHaveSameElement(words[i], chars);
        if (isHaveSameElement == true) {
            returnValue = returnValue + strlen(words[i]);
        }
    }

    return returnValue;
}
```
