### 解题思路
使用uthash

### 代码

```c
typedef struct {
    char name[16];
    int freq;
    UT_hash_handle hh;
} WordsFrequency;

WordsFrequency *g_head = NULL;

WordsFrequency* wordsFrequencyCreate(char** book, int bookSize) 
{
    WordsFrequency *s = NULL;
    int i;

    g_head = NULL;
    if (book == NULL || bookSize == 0) {
        return NULL;
    }

    for (i = 0; i < bookSize; i++) {
        HASH_FIND_STR(g_head, book[i], s);
        if (s == NULL) {
            s = (WordsFrequency *)malloc(sizeof(WordsFrequency));
            memset(s, 0, sizeof(WordsFrequency));
            s->freq++;
            strncpy(s->name, book[i], strlen(book[i]));
            HASH_ADD_STR(g_head, name, s);
        } else {
            s->freq++;
        }
    }
    return g_head;
}

int wordsFrequencyGet(WordsFrequency* obj, char* word) 
{
    WordsFrequency *s = NULL;
    HASH_FIND_STR(obj, word, s);
    if (s == NULL) {
        return 0;
    }
    return s->freq;
}

void wordsFrequencyFree(WordsFrequency* obj) 
{
    WordsFrequency *s = NULL;
    WordsFrequency *tmp = NULL;
    HASH_ITER(hh, obj, s, tmp) {
        HASH_DEL(obj, s);
        free(s);
    }
}
```