hash，关键在于要节省内存。
```
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <uthash.h>

struct MyHash {
    int key;
    short cnt;
    short *list;
    short listsize;
    UT_hash_handle hh;
};

struct MyHash *hash;

void HashAddVal(int val)
{
    struct MyHash *s = NULL;
    HASH_FIND_INT(hash, &val, s);

    if (s == NULL) {
        s = malloc(sizeof(*s));
        s->key = val;
        s->list = NULL;
        s->cnt = 0;
        s->listsize = 1;
        HASH_ADD_INT(hash, key, s);
    } else {
        s->listsize++;
    }
}

void HashAddIndex(int val, short index)
{
    struct MyHash *s = NULL;
    HASH_FIND_INT(hash, &val, s);

    if (s->cnt == 0) {
        s->list = malloc(sizeof(short) * s->listsize);
        /* printf("val %d cnt %d\n", val, s->listsize); */
    }

    s->list[s->cnt] = index;
    s->cnt++;
}

struct MyHash *HashFind(int val)
{
    struct MyHash *s = NULL;
    HASH_FIND_INT(hash, &val, s);
    return s;
}

/**
 *
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** computeSimilarities(int** docs, int docsSize, int* docsColSize, int* returnSize)
{
    if (docsSize < 2) {
        *returnSize = 0;
        return NULL;
    }

    hash = NULL;
    int i, j, k;
    for (i = 0; i < docsSize; i++) {
        for (j = 0; j < docsColSize[i]; j++) {
            HashAddVal(docs[i][j]);
        }
    }

    struct MyHash *s, *tmp;
    HASH_ITER(hh, hash, s, tmp) {
        if (s->listsize <= 1) {
            HASH_DEL(hash, s);
            free(s);
        }
    }

    int **dp = malloc(sizeof(int*) * docsSize);
    for (i = 0; i < docsSize; i++) {
        dp[i] = malloc(sizeof(int) * docsSize);
        memset(dp[i], 0, sizeof(int) * docsSize);
    }

    char **res = malloc(sizeof(char *) * 1000);
    int cnt = 0;
    for (i = 0; i < docsSize; i++) {
        for (j = 0; j < docsColSize[i]; j++) {
            struct MyHash *s = HashFind(docs[i][j]);

            if (s == NULL) {
                continue;
            }

            for (k = 0; k < s->cnt; k++) {
                dp[i][s->list[k]] += 1;
            }

            HashAddIndex(docs[i][j], i);
        }
    }



    for (int i = 1; i < docsSize; i++) {
        for (int k = 0; k < i; k++) {
            if (dp[i][k] > 0) {
                res[cnt] = malloc(sizeof(char) * 20);
                sprintf(res[cnt], "%d,%d: %.4f", k, i, dp[i][k] * 1.0 / (docsColSize[i] + docsColSize[k] - dp[i][k]) + 1e-9);
                cnt++;
            }
        }
        free(dp[i]);
    }

    *returnSize = cnt;
    return res;
}

```

![image.png](https://pic.leetcode-cn.com/a394cad2721286e005967044b9ba5ae0fca7c5a9a7b3c1e403e08873885ae44d-image.png)
