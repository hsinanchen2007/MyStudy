### 解题思路
1. 遍历words，弄一个hash，来计算次数
2. hash里每个节点同时加入一个双向基于频率排序的链表（fnext，fprev），同时保存链表的last节点
3. 每个新词加入hash或者老词增加次数后，返回这个节点，加入链表（新节点）或者节点往前移（次数增加了）
4. 3里有一些边界处理（新节点、空链表、首节点增加次数、尾节点增加次数、插入尾节点、插入首节点）
5. 非特殊情况，把当前节点先从链表里摘出来，按prev方向往前找到合适的位置插入


### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

typedef struct word {
    char *w;
    int cnt;
    struct word *next;
    struct word *fnext;
    struct word *fprev;
} WORD;

typedef struct freqlist {
    WORD *list;
    WORD *last;
    int listCnt;
} FREQLIST;

#define HASH_SIZE 32

int hashStr(char* str) {
    int i;
    int sum = 0;
    for (i=0; i<strlen(str); i++) {
        sum += str[i];
        sum %= HASH_SIZE;
    }
    return sum;
}

WORD* newWord(char *str) {
    WORD* word = (WORD*)malloc(sizeof(WORD));
    if (!word) {
        return NULL;
    }
    (void)memset(word, 0, sizeof(WORD));

    word->w = str;
    word->cnt = 1;
    return word;
}

WORD* searchHash(WORD *bucket, char *str) {
    WORD *cur = bucket;
    while (cur) {
        if (!strcmp(str, cur->w)) {
            return cur;
        }
        cur = cur->next;
    }
    return NULL;
}

WORD* addToHash(WORD **hashBucket, char *str) {
    int buckIdx = hashStr(str);
    WORD *w = searchHash(hashBucket[buckIdx], str);
    if (w == NULL) {
        w = newWord(str);
        w->next = hashBucket[buckIdx];
        hashBucket[buckIdx] = w;
    } else {
        w->cnt++;
    }
    return w;
}

void addToFreqList(FREQLIST *freq, WORD *w, int k) {
    WORD *cur = NULL;

    if (freq->list == NULL) {
        freq->list = freq->last = w;
        w->fnext = w->fprev = NULL;
        return;
    }

    if ((freq->last->cnt > w->cnt) ||
        (freq->last->cnt == w->cnt && strcmp(freq->last->w, w->w) < 0)) {
        freq->last->fnext = w;
        w->fprev = freq->last;
        freq->last = w;
        w->fnext = NULL;
        return;
    }

    if (w == freq->last) {
        if (freq->last->fprev) freq->last = freq->last->fprev;
    }

    if (w == freq->list) {/////
        if (freq->list->fnext) freq->list = freq->list->fnext;
    }

    if (w->fnext == NULL && w->fprev == NULL) {
        cur = freq->last;
    } else {
        cur = w->fprev;
        if (w->fprev) w->fprev->fnext = w->fnext;
        if (w->fnext) w->fnext->fprev = w->fprev;
        w->fnext = w->fprev = NULL;
    }
        
    while (cur) {
        if (cur->cnt > w->cnt ||
            ((cur->cnt == w->cnt) && (strcmp(cur->w, w->w) < 0))) {
            if (cur->fnext) cur->fnext->fprev = w;
            w->fnext = cur->fnext;
            w->fprev = cur;
            cur->fnext = w;
            if (cur == freq->last) freq->last = w;////////
            return;
        }
        cur = cur->fprev;
    }

    w->fnext = freq->list;
    freq->list->fprev = w;
    freq->list = w;
    w->fprev = NULL;
    return;
}

char ** topKFrequent(char ** words, int wordsSize, int k, int* returnSize) {
    if (words == NULL || wordsSize == 0) {
        *returnSize = 0;
        return NULL;
    }

    WORD *w;
    FREQLIST freqList = {0};
    WORD **hashBucket = (WORD**)malloc(sizeof(WORD*) * HASH_SIZE);
    if (hashBucket == NULL) {
        *returnSize = 0;
        return NULL;
    }
    (void)memset(hashBucket, 0, sizeof(WORD*) * HASH_SIZE);

    int i;
    for (i=0; i<wordsSize; i++) {
        w = addToHash(hashBucket, words[i]);
        addToFreqList(&freqList, w, k);
/*
        WORD *tmp = freqList.list;
        while (tmp) {
            printf(" %s(%d) ->", tmp->w, tmp->cnt);
            tmp = tmp->fnext;
        }
        printf("\n");
*/
    }

    WORD *cur = freqList.list;
    char **ret = (char**)malloc(sizeof(char*) * k);
    for (i=0; i<k; i++) {
        ret[i] = cur->w;
        cur = cur->fnext;
    }

    *returnSize = k;
    return ret;
}
```