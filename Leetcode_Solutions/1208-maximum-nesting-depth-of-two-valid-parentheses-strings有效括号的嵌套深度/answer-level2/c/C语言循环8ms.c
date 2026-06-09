![无标题.png](https://pic.leetcode-cn.com/46c698b3b2e2daeda1252b433ca4babc5de7a11ee3d739dc06665a1a6dc229fe-%E6%97%A0%E6%A0%87%E9%A2%98.png)

引入一个level，双层的分给A，单层的分给B。
```
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *maxDepthAfterSplit(char *seq, int *size)
{
    if (seq == NULL || *seq == '\0')
        return NULL;
    *size = strlen(seq);
    int *result = malloc(*size * sizeof(int));
    assert(result != NULL);

    int level = 0;
    for (int i = 0; i < *size; i++)
        result[i] = 1 & ((seq[i] == '(') ? level++ : --level);

    return result;
}
```
