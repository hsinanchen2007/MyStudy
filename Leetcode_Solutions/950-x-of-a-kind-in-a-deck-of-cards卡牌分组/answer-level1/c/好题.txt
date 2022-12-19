### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/573ee45c82ba1eb1aa2334ef7cbe392c8c23e81b0964724134bb6496b8ed549f-image.png)
这道题目坑有点多啊：
1) 一定是求不同数字的公约数，一定要 >=2, 比如4个1和6个2，这是可以分组的。我采取的是每两个相邻的个数就统计公约数
### 代码

```c
int cmp(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}

int gcd(int m, int n)
{
    int r;
    while (n) {
        r = m % n;
        m = n;
        n = r;
    }

    return m;
}

bool hasGroupsSizeX(int* deck, int deckSize){
    if (deckSize < 2) {
        return false;
    }

    qsort(deck, deckSize, sizeof(int), cmp);
    int flag = 0;
    int i, j;

    for (i = 0; i < deckSize; ) {
        for (j = i + 1; j < deckSize && deck[j] == deck[i]; j++) {
            ;
        }
        if (flag) {
            if (gcd(j - i, flag) < 2) {
                return false;
            }
        }
        flag = j - i;
        i = j;
    }

    return true;
}
```