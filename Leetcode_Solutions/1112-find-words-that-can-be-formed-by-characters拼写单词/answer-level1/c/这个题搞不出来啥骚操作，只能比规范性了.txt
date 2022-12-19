统计法
```c
#define LEN ('z' - 'a' + 1)
/* memset没这个快，memset是按字节赋值，这个按4字节赋值 */
static inline void wordZero(int *wmap, int len)
{
    for (int i = 0; i < len; i++) {
        wmap[i] = 0;
    }
    return;
}

/*不是每次alloc一个map，为了省内存*/
static inline void getMap(char *word, int *map)
{
    char *c = word;
    while (*c) {
        map[*c - 'a']++;
        c++;
    }
    return;
}
/* 只要word的某个字符比chars的多，就说明无法拼成单词。 */
static inline bool cmpMap(int *map1, int *map2, int n)
{
    for (int i = 0; i < n; i++) {
        if (map1[i] < map2[i]) {
            return false;
        }
    }
    return true;
}
int countCharacters(char ** words, int wordsSize, char * chars) {
    int map[LEN] = { 0 };
    getMap(chars, map);
    int wmap[LEN];
    int result = 0;
    for (int i = 0; i < wordsSize; i++) {
        wordZero(wmap, LEN);
        char *word = words[i];
        getMap(word, wmap);
        if (cmpMap(map, wmap, LEN)) {
            result += strlen(word);
        }
    }
    return result;    
}
```