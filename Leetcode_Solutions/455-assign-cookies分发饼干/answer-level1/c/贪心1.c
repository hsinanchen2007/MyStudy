### 解题思路
贪心，qsort先进行升序排列，然后由小到大，将最小的cookie分给最小需求的child，直到child或者cookie分完。

### 代码

```c
int comp(const void *a, const void *b)
{
    if (*(int *)a > *(int *)b)
        return 1;
    else
        return -1;
}

int findContentChildren(int* g, int gSize, int* s, int sSize)
{
    qsort(g, gSize, sizeof(int), comp);
    qsort(s, sSize, sizeof(int), comp);
    
    int child = 0;
    int cookie = 0;
    while (child < gSize && cookie < sSize)
    {
        if (g[child] <= s[cookie])
        {
            child ++;
            cookie ++;
        }
        else
        {
            cookie ++;
        }
    }
    
    return child;
}
```