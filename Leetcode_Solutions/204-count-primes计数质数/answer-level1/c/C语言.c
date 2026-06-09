### 解题思路
数组筛选过的，尝试用哈希表代替数组，但是明显多此一举，过不了

### 代码

```c
int countPrimes(int n){
    if (n < 2) return 0;
    int ret = 0;
    int i, j;
    int *primes = (int *)malloc(sizeof(int) * n);
    memset(primes, 0, sizeof(int) * n);
    for (i = 2; i < n; i++) {
        if (primes[i] == 0) {
            ret++;
            for (j = i + i; j < n; j += i) {
                primes[j] = 1;
            }
        }
    }
    return ret;
}
```
哈希表
```c
struct hash_node {
    int iKey;
    UT_hash_handle hh;
};

struct hash_node *g_hash = NULL;

struct hash_node *findNode(int iKey)
{
    struct hash_node *s = NULL;
    HASH_FIND_INT(g_hash, &iKey, s);
    return s;
}

void addNode(int iKey)
{
    struct hash_node *s = NULL;
    HASH_FIND_INT(g_hash, &iKey, s);
    if (s == NULL) {
        s = (struct hash_node*)malloc(sizeof(struct hash_node));
        s->iKey = iKey;
        HASH_ADD_INT(g_hash, iKey, s);
    }
    return;
}

void deleteALL()
{
    struct hash_node *current, *tmp;
    HASH_ITER(hh, g_hash, current, tmp) {
        HASH_DEL(g_hash, current);
        free(current);
    }
    return;
}

int countPrimes(int n){
    int i, j, k;
    int ans = 0;
    if (n < 2) return 0;
    struct hash_node *s = NULL;
    for (i = 2; i < n; i++) {
        s = findNode(i);
        if (s == NULL) {
            ans++;
            for (j = 2 * i; j < n; j += i) {
                addNode(j);
            }
        }
    }
    deleteALL();
    return ans;
}
```
