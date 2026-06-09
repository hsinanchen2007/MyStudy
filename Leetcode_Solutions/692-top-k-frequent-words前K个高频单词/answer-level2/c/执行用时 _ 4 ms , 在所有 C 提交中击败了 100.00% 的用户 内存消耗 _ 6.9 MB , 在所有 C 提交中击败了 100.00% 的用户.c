### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

typedef struct {
    int cnt;
    char buf[20];
} TopK;
TopK g_out[1000];

int Com(const void *a, const void *b)
{
    char *a1 = *(char **)a;
    char *b1 = *(char **)b;
    return strcmp(a1, b1);
}

int Com1(const void *a, const void *b)
{
    TopK a1 = *(TopK *)a;
    TopK b1 = *(TopK *)b;
    if (a1.cnt != b1.cnt) {
        return a1.cnt < b1.cnt;
    }
    return strcmp(a1.buf, b1.buf);
}

char ** topKFrequent(char ** words, int wordsSize, int k, int* returnSize){
    *returnSize = 0;
    memset(g_out, 0, sizeof(g_out));
    qsort(words, wordsSize, sizeof(char *), Com);

    int j = 0;
    bool same = false;
    for (int i = 0; i < wordsSize - 1; i++) {
        g_out[j].cnt++;
        if (g_out[j].buf[0] == 0) {
            strcpy(g_out[j].buf, words[i]);
        }

        if (strcmp(words[i], words[i + 1]) == 0) {
            same = true;
            continue;
        }
        j++;
        same = false;
    }
    int num = j;
    if  (same) {
        g_out[num].cnt++;
    } else {
        num++;
        g_out[num].cnt = 1;
        strcpy(g_out[num].buf, words[wordsSize - 1]);
    }
    num++;
    qsort(g_out, num, sizeof(TopK), Com1);

    *returnSize = k;
    char **out = (char **)malloc(sizeof(char *) * k);
    for (int i = 0; i < k; i++) {
        out[i] = (char *)malloc(20);
        memset(out[i], 0, 20);
        strcpy(out[i], g_out[i].buf);
    }
    return out;
}
```