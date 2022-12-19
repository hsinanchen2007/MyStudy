### 解题思路
哈希表的key值是字符串，这里要注意uthash的接口中对字符串与字符指针的区别，别的就没什么大问题了；
wordsFrequencyCreate就是调用addNode把单词写入哈希表，wordsFrequencyGet就是find的实现，wordsFrequencyFree就是deleteAll的实现

### 代码

```c
typedef struct {
    char name[12];
    int freq;
    UT_hash_handle hh;
} WordsFrequency;

WordsFrequency *g_hash = NULL;

void addNode(char *name)
{
    WordsFrequency *s = NULL;
    HASH_FIND_STR(g_hash, name, s);
    if (s == NULL) {
        s = (WordsFrequency *)malloc(sizeof(WordsFrequency));
        strcpy(s->name, name);
        s->freq = 1;
        HASH_ADD_STR(g_hash, name, s);
    } else {
        s->freq += 1;
    }
    return;
}

WordsFrequency* wordsFrequencyCreate(char** book, int bookSize) {
    int i;
    for (i = 0; i < bookSize; i++) {
        addNode(book[i]);
    }
    return g_hash;
}

int wordsFrequencyGet(WordsFrequency* obj, char* word) {
    WordsFrequency *s = NULL;
    HASH_FIND_STR(g_hash, word, s);
    if (s == NULL) {
        return 0;
    } else {
        return s->freq;
    }
}

void wordsFrequencyFree(WordsFrequency* obj) {
    WordsFrequency *current, *tmp;
    HASH_ITER(hh, g_hash, current, tmp) {
        HASH_DEL(g_hash, current);
        free(current);
    }
    return;
}

/**
 * Your WordsFrequency struct will be instantiated and called as such:
 * WordsFrequency* obj = wordsFrequencyCreate(book, bookSize);
 * int param_1 = wordsFrequencyGet(obj, word);
 
 * wordsFrequencyFree(obj);
*/
```