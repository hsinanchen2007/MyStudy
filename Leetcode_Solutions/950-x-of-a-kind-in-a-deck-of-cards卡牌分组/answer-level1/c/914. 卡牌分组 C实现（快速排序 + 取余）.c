### 解题思路
        快速排序后统计每个元素的出现次数，取出现次数最小的次数遍历取余。

### 代码

```c
int Compare(const void* a, const void* b)
{
    return *(int*)a - *(int*)b;
}

bool hasGroupsSizeX(int* deck, int deckSize){
    if (!deck || deckSize <=1) {
        return false;
    }
    qsort(deck, deckSize, sizeof(int), Compare);
    int* cnt = (int*)malloc(sizeof(int) * deckSize);
    int cntSize = -1;
    int cur = -1;
    for (int i = 0; i < deckSize; i++) {
        if (cur != deck[i]) {
            cur = deck[i];
            cnt[++cntSize] = 1;
        } else {
            cnt[cntSize]++;
        }
    }
    qsort(cnt, cntSize + 1, sizeof(int), Compare);
    for (int i = 2; i <= cnt[0]; i++) {
        for (int j = 0; j <= cntSize; j++) {
            if (cnt[j] % i != 0) {
                break;
            }
            if (j == cntSize) {
                free(cnt);
                return true;
            }
        }
    }
    free(cnt);
    return false;
}
```