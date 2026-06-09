### 解题思路
C语言使用UTHash实现，单词作为key，按照次数排序

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define MAX_SIZE 28
typedef struct {
    char word[MAX_SIZE];
    int cnt;
    UT_hash_handle hh;
} HashType;

HashType *g_user = NULL;

int comp(const void *a, const void *b)
{
    HashType *pa = (HashType*)a;
    HashType *pb = (HashType*)b;
    if (pb->cnt == pa->cnt) {
        return strcmp(pa->word, pb->word);
    }
    return pb->cnt - pa->cnt;
}

void hashBuild(char **words, int wordsSize)
{
    for (int i = 0; i < wordsSize; i++) {
        HashType *s = NULL;
        HASH_FIND_STR(g_user, words[i], s);
        if (s) {
            s->cnt++; 
        } else {
            s = (HashType*)malloc(sizeof(HashType));
            strcpy(s->word, words[i]);
            HASH_ADD_STR(g_user, word, s);
            s->cnt = 1;
        }
    }
    HASH_SORT(g_user, comp);
    return;
}

char ** topKFrequent(char ** words, int wordsSize, int k, int* returnSize){
    HashType *s = NULL;
    HashType *tmp = NULL;
    int cur = 0;
    char **ans = (char**)malloc(sizeof(char*) * wordsSize);
    hashBuild(words, wordsSize);

    HASH_ITER(hh, g_user, s, tmp) {
        ans[cur] = (char*)malloc(MAX_SIZE);
        strcpy(ans[cur], s->word);
        cur++;
        HASH_DEL(g_user, s);
        free(s);
    }
    g_user = NULL;
    *returnSize = k;
    return ans;
}
```