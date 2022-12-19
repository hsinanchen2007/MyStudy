### 1、回溯（超时）
1. 先将coins按降序排个序（其实不排也行）
2. 处理coins[0]，可以取i个，i的范围是[0个，remain(最初值为amount)/coins[0]]
3. 回溯，选择coins[1]可能的取值，remain为amount-coins[0]*i
4. remain为0时表示找到了一个解，维护一个最小值

### 代码

```c
int cmp(const void *a, const void *b) {
    return *(int*)b - *(int*)a;
}

bool backtrace(int amount, int remain, int *coins, int coinsSize, int idx, int *cnt, int *min) {
    if (remain == 0) {
        *min = (*min == -1) ? *cnt : fmin(*min, *cnt);
        return true;
    }

    while (idx < coinsSize && coins[idx] > remain) idx++;
    if (idx >= coinsSize) return false;

    int trycnt = remain / coins[idx];
    int i;
    int flag = false;
    for (i=trycnt; i>=0; i--) {///>=0
        int tmp = *cnt;
        *cnt += i;
        bool ret = backtrace(amount, remain-coins[idx]*i, coins, coinsSize, idx+1, cnt, min);
        if (ret) flag = true;
        *cnt = tmp;
    }
    return flag;
}

int coinChange(int* coins, int coinsSize, int amount){
    qsort(coins, coinsSize, sizeof(int), cmp); 
    int cnt = 0;
    int min = -1;
    if (backtrace(amount, amount, coins, coinsSize, 0, &cnt, &min)) {
        return min;
    }
}
```

### 2、动态规划
1. f[s]表示金额s所需的最小硬币数
2. f[0] = 0
3. 无解时f[i] = -1
4. 一般情况下，对于f[i-coins[idx]]有解的情况（idx的最大值是coins[idx]不大于i），f[i]是这些解中的最小值，即：
```
f[i] = min( f[i-coins[0]]+1, f[i-coins[1]+1, ... f[i-coins[m]+1] )
```

```c
int cmp_asend(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}

int coinChange(int* coins, int coinsSize, int amount){
    qsort(coins, coinsSize, sizeof(int), cmp_asend);
    int *f = (int*)malloc(sizeof(int) * (amount+1));
    int i;
    for (i=0; i<=amount; i++) {
        if (i==0) {
            f[i] = 0;
            continue;
        }
        else if (i < coins[0]) {
            f[i] = -1;
            continue;
        }

        int j;
        for (j=0; j<coinsSize; j++) {
            if (coins[j] > i) break;
        }
        int k;
        int num = -1;
        for (k=0; k<j; k++) {
            if (f[i-coins[k]] != -1) {
                num = (num == -1) ? (f[i-coins[k]]+1) : fmin(num, f[i-coins[k]]+1);
            }
        }
        f[i] = num;
    }
    return f[amount];
}
```