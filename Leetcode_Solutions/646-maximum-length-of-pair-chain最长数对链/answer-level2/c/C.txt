
![1.png](https://pic.leetcode-cn.com/6007ad58fb1f2af1d8a34e426e8195e8368d1a2bcdb80ee56e32a53d629740f1-1.png)

```
#define MAX_NUM 1000

struct PairStr {
    int start;
    int end;
};

int Cmp(const void *a, const void *b)
{
    return ((struct PairStr *)a)->start - ((struct PairStr *)b)->start;
}

int findLongestChain(int **pairs, int pairsSize, int *pairsColSize)
{
    struct PairStr pairInfo[MAX_NUM];
    int count = 1;
    int temp = pairsSize - 1;

    *pairsColSize = 2;
    for (int i = 0; i < pairsSize; i++) {
        pairInfo[i].start = pairs[i][0];
        pairInfo[i].end = pairs[i][1];
    }
    //考虑到数对第一个数字总比第二个数字小，因此可以基于第一个或者第二个排序
    qsort(pairInfo, pairsSize, sizeof(struct PairStr), Cmp);
    //可以采用贪心或者动归
    for (int i = pairsSize - 1; i > 0; i--) {
        if (pairInfo[temp].start > pairInfo[i - 1].end) {
            temp = i - 1; //满足要求则更新
            count++;
        }
    }

    return count;
}
```
