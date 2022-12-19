### 解题思路
这个比较麻烦的是状态方程
说一下状态的含义
dp[amount]有以下取值
- -1，说明无解
- 0，初始化状态，说明还没有计算过
- 正数，对应mount的最优解
![image.png](https://pic.leetcode-cn.com/be6d642075d4d3a6ff51b485293c5a14312560f5cb5b064d71895c374bb6ea3c-image.png)

### 代码

```c
#define MY_OK 0
#define MY_FAIL (-1)

typedef struct {
    int *coins;
    int coinsSize;
    int *dp;
    int dpSize;
} MyStatus;
void sFree(MyStatus *s)
{
    if (s->dp != NULL) {
        free(s->dp);
        s->dp = NULL;
    }
    return;
}
int sInit(MyStatus *s, int* coins, int coinsSize, int amount)
{
    int i;
    s->coins = coins;
    s->coinsSize = coinsSize;
    s->dp = (int*)calloc(amount + 1, sizeof(int));
    if (s->dp == NULL) {
        return MY_FAIL;
    }
    for (i = 0; i < coinsSize; i++) {
        s->dp[coins[i]] = 1;
    }
    s->dpSize = amount + 1;
    return MY_OK;
}
void trace(MyStatus *s)
{
    int i;
    for (i = 0; i < s->dpSize; i++) {
        printf("[%d] = %d,", i, s->dp[i]);
    }
    printf("\n");
}
int process(MyStatus *s, int amount)
{
    int i;
    int rc;
    int min = INT_MAX;
    if (amount < 0) {
        return -1;
    }
    if (s->dp[amount] != 0) {
        return s->dp[amount];
    }
    for (i = 0; i < s->coinsSize; i++) {
        rc = process(s, amount - s->coins[i]);
        if (rc < 0) {
            continue;
        }
        min = min < (rc + 1) ? min : (rc + 1);
    }
    s->dp[amount] = min == INT_MAX ? -1 : min;
    return s->dp[amount];
}
int cmp(const void *a, const void *b)
{
    return *(int*)a > *(int*)b;
}
void prepare(int* coins, int *coinsSize, int amount)
{
    int i;
    qsort(coins, *coinsSize, sizeof(int), cmp);
    for (i = 0; i < *coinsSize; i++) {
        if (coins[i] > amount) {
            break;
        }
    }
    *coinsSize = i;
    return;
}
int coinChange(int* coins, int coinsSize, int amount){
    int rlt, ret;
    MyStatus s;
    if (amount == 0) {
        return 0;
    }
    prepare(coins, &coinsSize, amount);
    if (amount < 0 || coinsSize <= 0) {
        return -1;
    }
    ret = sInit(&s, coins, coinsSize, amount);
    if (ret != MY_OK) {
        return -1;
    }
    process(&s, amount);
    //trace(&s);
    rlt = s.dp[amount];
    sFree(&s);
    return rlt;
}
```