### 解题思路
此处撰写解题思路

### 代码

```c
#define CHARNUMS 26

bool MasterWord(char* s, int* map, int* mapTemp)
{
    memcpy(mapTemp, map, sizeof(int) * CHARNUMS);
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        int index = s[i] - 'a';
        if (mapTemp[index] > 0) {
            mapTemp[index]--;
        } else {
            return false;
        }
    }
    return true;
}

int countCharacters(char ** words, int wordsSize, char * chars){
    if (!words || !chars || wordsSize <= 0) {
        return 0;
    }
    int len = 0;
    int mallocSize = sizeof(int) * CHARNUMS;
    int* map = (int*)malloc(mallocSize);
    memset(map, 0, mallocSize);
    int* mapTemp = (int*)malloc(mallocSize);
    int charsLen = strlen(chars);
    for (int i = 0; i < charsLen; i++) {
        map[chars[i] - 'a']++;
    }
    for (int i = 0; i < wordsSize; i++) {
        if (MasterWord(words[i], map, mapTemp)) {
            len += strlen(words[i]);
        }
    }
    free(mapTemp);
    free(map);
    return len;
}
```