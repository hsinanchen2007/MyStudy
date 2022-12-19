### 解题思路
统计次数，求所有次数的最大公约数

### 代码

```c

struct hashNode {
    int val;
    int cnt;
    UT_hash_handle hh;
};

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

bool hasGroupsSizeX(int* deck, int deckSize){
    if (!deck || deckSize == 1) return false;

    struct hashNode *htable = NULL;
    for (int i = 0; i < deckSize; i++) {
        struct hashNode *n = NULL;
        HASH_FIND_INT(htable, &deck[i], n);
        if (!n) {
            n = (struct hashNode*)malloc(sizeof(struct hashNode));
            n->val = deck[i];
            n->cnt = 1;
            HASH_ADD_INT(htable, val, n);
        } else {
            n->cnt += 1;
        }
    }

    struct hashNode *cur, *tmp;
    int cnt = 0;
    int a, b;
    int g = -1;
    bool flag = true;
    HASH_ITER(hh, htable, cur, tmp) {
        if (g == -1) {
            g = cur->cnt;
        } else {
            g = gcd(g, cur->cnt);
        }
        HASH_DEL(htable, cur);
        free(cur);
    }

    return g>=2;
}
```