排序+二分查找

首先按照题目的3种情况分别对`wordlist`的索引排序，排序结果保存在三个索引数组中：
1. `pidx`: `wordlist[pidx[i]]`按照区分大小写的字典序排序（以下代码中`pcmp`函数）
2. `cidx`: `wordlist[cidx[i]]`按照不区分大小写的字典序排序，注意当字符串相等时，按照`wordlist`的原索引排序（以下代码中`ccmp`函数）
3. `vidx`: `wordlist[vidx[i]]`按照不区分大小写及元音的字典序排序，即在不区分大小的基础上，相同位置若为不同元音也认为相同，当包含元音字母时需要转为统一字符（如*）再进行不相等比较，否则会造成可替换元音字符串排序不一致，注意当字符串相同时，按照`wordlist`的原索引排序（以下代码中`vcmp`函数）

然后遍历`queries`，按照以下顺序分别二分查找：
1. `pidx`：表示完全匹配的情况（`strcmp`函数比较）
2. `cidx`：表示忽略大小写匹配的情况（以下代码中`crank`函数比较）
3. `vidx`：表示元音匹配的情况（以下代码中`vrank`函数比较）
4. 若前三个搜索都没找到，填入空字符串
二分查找时需要一直找到最左侧相等的字符串，而不是遇到相等就立即返回。

```
char **g_wordlist;

static inline char tolowerx(char v)
{
    if (v >= 'A' && v <= 'Z') {
        v = v - 'A' + 'a';
    }
    return v;
}

static inline int isvol(char v)
{
    return v == 'a' || v == 'e' || v == 'i' || v == 'o' || v == 'u';
}

int *initIndex(int size)
{
    int *ret = malloc(sizeof (int) * size);
    for (int i = 0; i < size; i++) {
        ret[i] = i;
    }
    return ret;
}

int pcmp(const void *a, const void *b)
{
    int ia = *(const int *)a;
    int ib = *(const int *)b;
    return strcmp(g_wordlist[ia], g_wordlist[ib]);
}

int crank(const char *sa, const char *sb)
{
    for (; *sa || *sb; sa++, sb++) {
        int a = tolowerx(*sa);
        int b = tolowerx(*sb);
        if (a != b) {
            return (int)a - (int)b;
        }
    }
    return 0;
}

int ccmp(const void *a, const void *b)
{
    int ia = *(const int *)a;
    int ib = *(const int *)b;
    char *sa = g_wordlist[ia];
    char *sb = g_wordlist[ib];
    int r = crank(sa, sb);
    return r ? r : ia - ib;
}

int vrank(const char *sa, const char *sb)
{
    for (; *sa || *sb; sa++, sb++) {
        int a = tolowerx(*sa);
        int b = tolowerx(*sb);
        if (isvol(a)) {
            a = '*';
        }
        if (isvol(b)) {
            b = '*';
        }
        if (a != b) {
            return (int)a - (int)b;
        }
    }
    return 0;
}

int vcmp(const void *a, const void *b)
{
    int ia = *(const int *)a;
    int ib = *(const int *)b;
    char *sa = g_wordlist[ia];
    char *sb = g_wordlist[ib];
    int r = vrank(sa, sb);
    return r ? r : ia - ib;
}

typedef int (*Compx)(const char *a, const char *b);

int find(int *xidx, int size, char *query, Compx compx)
{
    int left = 0;
    int right = size - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        int val = compx(g_wordlist[xidx[mid]], query);
        if (val >= 0) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    int ret = right + 1;
    if (ret < size && compx(g_wordlist[xidx[ret]], query) == 0) {
        return xidx[ret];
    }
    return -1;
}

char ** spellchecker(char ** wordlist, int wordlistSize, char ** queries, int queriesSize, int* returnSize)
{
    int *pidx = initIndex(wordlistSize);
    int *cidx = initIndex(wordlistSize);
    int *vidx = initIndex(wordlistSize);
    g_wordlist = wordlist;
    qsort(pidx, wordlistSize, sizeof (int), pcmp);
    qsort(cidx, wordlistSize, sizeof (int), ccmp);
    qsort(vidx, wordlistSize, sizeof (int), vcmp);

    *returnSize = queriesSize;
    char **ret = malloc(sizeof (char *) * queriesSize);
    for (int i = 0; i < queriesSize; i++) {
        int id;
        id = find(pidx, wordlistSize, queries[i], strcmp);
        if (id >= 0) {
            ret[i] = wordlist[id];
            continue;
        }
        id = find(cidx, wordlistSize, queries[i], crank);
        if (id >= 0) {
            ret[i] = wordlist[id];
            continue;
        }
        id = find(vidx, wordlistSize, queries[i], vrank);
        if (id >= 0) {
            ret[i] = wordlist[id];
            continue;
        }
        ret[i] = "";
    }

    free(pidx);
    free(cidx);
    free(vidx);
    return ret;
}
```