### 解题思路
看代码就能懂

### 代码

```c
/* 卡牌分组 */

int cmp(const void *a, const void *b)
{
    return *((int *)a) - *((int *)b);
}

bool hasGroupsSizeX(int *deck, int deckSize)
{
    if ((deck == NULL) || (deckSize < 2)) {
        return false;
    }

    int count;
    int isCan;
    qsort(deck, deckSize, sizeof(int), cmp);

    for (int x = 2; x <= deckSize; x++) {
        // 卡牌是否能分组
        if (deckSize % x != 0) {
            continue;
        }
        count = 1;
        isCan = 1;
        for (int i = 0; i < deckSize - 1; i++) {
            if (deck[i] == deck[i + 1]) {
                count++;
            } else {
                printf("else  %d\n ", count);
                if (count % x != 0) {
                    isCan = 0;
                    break;
                }
                count = 1;
            }
        }

        if (isCan == 1) {
            return true;
        }
    }

    return false;
}
```