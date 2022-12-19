方法一、用所有牌数量的最大公约数。所有牌的数量，如果有共同的约数（最大公约数当然也是可以的，而求最大公约数比较方便，所以就用最大公约数），而这个约数>=2，则满足要求，
```
int gcd(int x, int y) {
    return x == 0 ? y : gcd(y%x, x);
}

#define N 10000
bool hasGroupsSizeX(int* deck, int deckSize){
    int count[N]= {0};
    for (int i = 0; i < deckSize; i++) {
        count[deck[i]]++;
    }

    int g = -1;
    for (int i = 0; i < N; i++) {
        if (count[i] > 0) {
            if (g == -1) {
                g = count[i];
            } else {
                g = gcd(g, count[i]);
            } 
        }
    }

    return g >= 2;
}
```

时间复杂度：nlog(N)，求数量是n，最大公约数是log(n), 需要n - 1次
空间复杂度：O(N)

方法二、找出最小的那个数量，如果此数量的大于2的约数中存在一个约数，能被所有其他数量整除，则返回成功。一个都不存在则返回失败。


a、可以用HASH找数量
```
#define N 10000
bool hasGroupsSizeX(int* deck, int deckSize){    
    int count[N]= {0};
    for (int i = 0; i < deckSize; i++) {
        count[deck[i]]++;
    }

    int min = INT_MAX;
    for (int i = 0; i < N; i++) {
        if (count[i] != 0) {
            min = (min < count[i] ? min : count[i]);
        }
    }

    if (min < 2) {
        return false;
    }
    
    for (int k = 2; k <= min; k++) {
        if (min % k == 0) {
            int i = 0;
            for (; i < N; i++) {
                if (count[i] != 0 && count[i] % k != 0) {
                    break;
                }
            }

            if (i == N) {
                return true;
            }
        }
    }

    return false;
}
```

b、可以排序找数量，好处是同时也找出了最小数量
```
int comp(const void* a, const void* b) {
    return (*(int*)a) > (*(int*)b) ? 1 : -1;
}

bool hasGroupsSizeX(int* deck, int deckSize){
    int dp[deckSize];
    for (int i = 0; i < deckSize; i++) {
        dp[i] = 0;
    }
    int total = 0;
    qsort(deck, deckSize, sizeof(int), comp);
    int min = deckSize;
    for (int i = 0; i < deckSize;) {
        int j;
        for (j = i + 1; j < deckSize; j++) {
            if (deck[j] != deck[i]) {
                break;
            }
        }
        dp[total++] = j - i;
        min = (min < j - i) ? min : j - i;
        i = j;
    }

    if (min < 2) {
        return false;
    }
    
    for (int k = 2; k <= min; k++) {
        if (min % k == 0) {
            int i = 0;
            for (; i < total; i++) {
                if (dp[i] % k != 0) {
                    break;
                }
            }

            if (i == total) {
                return true;
            }
        }
    }

    return false;
}
```

