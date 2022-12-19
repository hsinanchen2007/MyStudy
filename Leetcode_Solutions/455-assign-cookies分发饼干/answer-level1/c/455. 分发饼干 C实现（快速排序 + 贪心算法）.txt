### 解题思路
    快速排序，依次喂饼干，每次都在损失最小的情况下喂饱小孩子。

### 代码

```c
int Cmp(const void* a, const void* b)
{
    return *(int*)a -*(int*)b;
}

int findContentChildren(int* g, int gSize, int* s, int sSize)
{
    if (!g || gSize <= 0 || !s || sSize <= 0) {
        return 0;
    }
    qsort(g, gSize, sizeof(int), Cmp);
    qsort(s, sSize, sizeof(int), Cmp);
    int mallocSize = sizeof(bool) * gSize;
    int idx = 0;
    int ret = 0;
    for (int i = 0; i < sSize; i++) {
        if (idx >= gSize) {
            break;
        }
        if (s[i] >= g[idx]) {
            ret++;
            idx++;
            continue;
        } else {
            continue;
        }
    }
    return ret;
}
```