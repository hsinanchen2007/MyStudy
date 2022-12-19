### 解题思路
转成比较字符串就容易了，不过确实慢了不少

![image.png](https://pic.leetcode-cn.com/723f693bcf9264be57362a3870949e58f04a5a435f8cada543e3301d4b637377-image.png)

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define MY_MAX 20
char g_sa[MY_MAX];
char g_sb[MY_MAX];
int cmp(const void *a, const void *b)
{
    int *pa = (int*)a;
    int *pb = (int*)b;
    sprintf(g_sa, "%d", *pa);
    sprintf(g_sb, "%d", *pb);
    return strcmp(g_sa, g_sb);
}
int* proc(int n, int* returnSize){
    int i;
    int *rlt = (int*)calloc(n, sizeof(int));
    if (rlt == NULL) {
        return NULL;
    }
    for (i = 0; i < n; i++) {
        rlt[i] = i + 1;
    }
    qsort(rlt, n, sizeof(int), cmp);
    *returnSize = n;
    return rlt;
}
int* lexicalOrder(int n, int* returnSize){
    if (n <= 0) {
        returnSize = 0;
        return NULL;
    }
    return proc(n, returnSize);
}
```