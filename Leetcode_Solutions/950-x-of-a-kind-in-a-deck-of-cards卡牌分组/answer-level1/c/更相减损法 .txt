1. 先统计各个数字的个数
2. 在求所有个数的最大公约数
3. 大于2，返回true; 否则返回false

```
#define LEN 10000

int getGcd(int a, int b)
{
    while (a != b) {
        if (a > b) {
            a = a - b;
        } else {
            b = b - a;
        }
    }
    return a;
}

bool hasGroupsSizeX(int* deck, int deckSize)
{
    if (deckSize < 2) {
        return false;
    }

    int cnt[LEN];
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < deckSize; i++) {
        cnt[deck[i]]++;
    }

    int gcd = 0;
    for (int i = 0; i < LEN; i++) {
        if (cnt[i]) {
            if (gcd == 0) {
                gcd = cnt[i];
            } else {
                gcd = getGcd(gcd, cnt[i]);             
                if (gcd <= 1) {
                    return false;
                }
            }
        }
    }
    return true;
}
```

