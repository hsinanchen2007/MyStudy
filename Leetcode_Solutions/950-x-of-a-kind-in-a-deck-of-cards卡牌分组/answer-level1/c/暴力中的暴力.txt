### 解题思路
1、先把数组从小到大进行排序；
2、申请一个动态空间，将出现的数字的次数存起来；
3、找出次数出现的最少次数（可以是最大公约数），最小次数为1，可以直接返回false;
4、如果出现的次数中能被最小次数整除，就可以分成X组；


### 代码

```c
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int compare(void *a, void *b)
{
    return (*(int *)a - *(int *)b);
}

int gcd(int a, int b)
{
    if (b == 0) {
        return a;
    }

    return gcd(b, a % b);
}

bool hasGroupsSizeX(int* deck, int deckSize)
{
    int i;
    int *cnt;
    int idx = 0;
    int len;
    int min = deckSize;

    if (deckSize <= 1) {
        return false;
    }

    qsort(deck, deckSize, sizeof(int), compare);

    len = deck[deckSize-1] - deck[0] + 1;
    cnt = (int *)calloc(len, sizeof(int));

    for (i = 0; i < len; i++) {
        cnt[i] = 1;
    }

    for (i = 1; i < deckSize; i++) {
        if (deck[i] == deck[i-1]) {
            cnt[idx]++;
            continue;
        }

        idx++;
    }

    for (i = 0; i < len; i++) {
        min = MIN(min, gcd(min, cnt[i]));
//        printf("min=%d cnt[%d]=%d\n", min, i, cnt[i]);
        if (min == 1) {
            free(cnt);
            return false;
        }
    }

    for (i = 0; i < len; i++) {
        if (cnt[i] % min != 0) {
            free(cnt);
            return false;
        }
    }

    free(cnt);
    return true;
}
```