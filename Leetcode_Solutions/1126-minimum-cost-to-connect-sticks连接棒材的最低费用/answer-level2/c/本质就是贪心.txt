### 解题思路
先从小到大排序，一直计算当前最小的数组前两个就行了，每次X+Y再插入到有序的数组中

### 代码

```c
int Comp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int connectSticks(int* sticks, int sticksSize)
{
    qsort(sticks, sticksSize, sizeof(int), Comp);

    if (sticksSize == 1) {
        return 0;
    }

    int res = 0;
    for (int i = 0; i < sticksSize - 1; i++) {
        int last = sticks[i] + sticks[i + 1];
        res += last;   
           
        int j = i + 2;
        sticks[i + 1] = last;
        /* 当前X+Y，有序的插入新数组中，本质就是找到比他大的数就结束 */
        while (j < sticksSize && last > sticks[j]) {
            int temp = sticks[j];
            sticks[j] = last;
            sticks[j - 1] = temp;
            j++;
        }
    }
    
    return res;
}
```